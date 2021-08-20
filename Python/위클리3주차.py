from collections import defaultdict

direction_x = [-1, 1, 0, 0]
direction_y = [0, 0, -1, 1]
blocks = defaultdict(list)
visited = []


def make_rotation(index, count, block_list):
    global blocks

    rotate = [[-arr[1], arr[0]] for arr in block_list]

    if rotate == blocks[index][0] and count is not 0:
        return

    blocks[index].append(rotate)
    make_rotation(index, count+1, rotate)


def search(x, y, count, game_board):
    global visited
    visited[x][y] = True

    for i in range(0, 4):
        px = x + direction_x[i]
        py = y + direction_y[i]
        if 0 <= px < len(game_board) and 0 <= py < len(game_board) and game_board[px][py] == 0 and \
                visited[px][py] is False:
            arr = search(px, py, count, game_board)
            blocks[count][0].append(arr)

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
        print("k: ", k)
        print(blocks[k])

    answer = -1
    return answer


answer = solution([[1, 1, 0, 0, 1, 0], [0, 0, 1, 0, 1, 0], [0, 1, 1, 0, 0, 1], [1, 1, 0, 1, 1, 1], [1, 0, 0, 0, 1, 0],
          [0, 1, 1, 1, 0, 0]],
         [[1, 0, 0, 1, 1, 0], [1, 0, 1, 0, 1, 0], [0, 1, 1, 0, 1, 1], [0, 0, 1, 0, 0, 0], [1, 1, 0, 1, 1, 0],
          [0, 1, 0, 0, 0, 0]])

print(answer)