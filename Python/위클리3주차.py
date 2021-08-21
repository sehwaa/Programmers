from collections import defaultdict

direction_x = [-1, 1, 0, 0]
direction_y = [0, 0, -1, 1]
blocks = defaultdict(list)
table_blocks = defaultdict(list)
visited = []


def make_rotation(index, count, block_list):
    global blocks

    rotate = [[-arr[1], arr[0]] for arr in block_list]

    if rotate == blocks[index][0] and count is not 0:
        return

    blocks[index].append(rotate)
    make_rotation(index, count+1, rotate)


def make_rotation_table(index, count, block_list):

    rotate = [[-arr[1], arr[0]] for arr in block_list]

    if rotate == table_blocks[index][0] and count is not 0:
        return

    table_blocks[index].append(rotate)
    make_rotation_table(index, count+1, rotate)


def search(x, y, count, board):
    global visited
    visited[x][y] = True

    for i in range(0, 4):
        px = x + direction_x[i]
        py = y + direction_y[i]
        if 0 <= px < len(board) and 0 <= py < len(board) and board[px][py] == 0 and \
                visited[px][py] is False:
            arr = search(px, py, count, board)
            blocks[count][0].append(arr)

    return [x, y]


def search_table(x, y, count, board):
    global visited
    visited[x][y] = True

    for i in range(0, 4):
        px = x + direction_x[i]
        py = y + direction_y[i]
        if 0 <= px < len(board) and 0 <= py < len(board) and board[px][py] == 1 and \
                visited[px][py] is False:
            arr = search_table(px, py, count, board)
            table_blocks[count][0].append(arr)

    return [x, y]


def solution(game_board, table):
    global visited
    for arr in game_board:
        temp = []
        for i in arr:
            temp.append(False)
        visited.append(temp)

    count = 0
    for x_idx, arr in enumerate(game_board):
        for y_idx, value in enumerate(arr):
            if value == 0 and visited[x_idx][y_idx] == False:
                blocks[count].append([])
                arr = search(x_idx, y_idx, count, game_board)
                blocks[count][0].append(arr)
                count += 1

    for k in blocks.keys():
        make_rotation(k, 0, blocks[k][0])

    for i in blocks.keys():
        blocks[i].append(len(blocks[i][0]))

    visited = []

    for arr in table:
        temp = []
        for i in arr:
            temp.append(False)
        visited.append(temp)

    count = 0
    for x_idx, arr in enumerate(table):
        for y_idx, value in enumerate(arr):
            if value == 1 and visited[x_idx][y_idx] == False:
                table_blocks[count].append([])
                arr = search_table(x_idx, y_idx, count, table)
                table_blocks[count][0].append(arr)
                count += 1

    for k in table_blocks.keys():
        make_rotation_table(k, 0, table_blocks[k][0])

    for i in table_blocks.keys():
        table_blocks[i].append(len(table_blocks[i][0]))

    print(blocks)
    print(table_blocks)


    answer = -1
    return answer


answer = solution([[1, 1, 0, 0, 1, 0], [0, 0, 1, 0, 1, 0], [0, 1, 1, 0, 0, 1], [1, 1, 0, 1, 1, 1], [1, 0, 0, 0, 1, 0],
          [0, 1, 1, 1, 0, 0]],
         [[1, 0, 0, 1, 1, 0], [1, 0, 1, 0, 1, 0], [0, 1, 1, 0, 1, 1], [0, 0, 1, 0, 0, 0], [1, 1, 0, 1, 1, 0],
          [0, 1, 0, 0, 0, 0]])

print(answer)