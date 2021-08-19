from collections import defaultdict

direction_x = [-1, 1, 0, 0]
direction_y = [0, 0, -1, 1]
blocks = defaultdict(list)
visited = []


def make_rotation(x, y):
    pass


def search(x, y, count, game_board):
    global visited
    visited[x][y] = True

    for i in range(0, 4):
        px = x + direction_x[i]
        py = y + direction_y[i]
        if px >= 0 and py >= 0 and px < len(game_board) and py < len(game_board) and game_board[px][py] == 0 and \
                visited[px][py] == False:
            arr = search(px, py, count, game_board)
            blocks[count].append(arr)

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
                arr = search(x_idx, y_idx, count, game_board)
                blocks[count].append(arr)
                count += 1

    print(blocks)
    answer = -1
    return answer