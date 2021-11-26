X = [0, -1, 1, 0]
Y = [1, 0, 0, -1]


def dfs(i, j, value, startX, startY):
    global arr
    global visited

    v = arr[i][j]
    arr[i][j] = value

    if i == startX and j == startY:
        return

    for n in range(0, 4):
        px = X[n] + i
        py = Y[n] + j

        if visited[px][py] == True:
            print(str(px) + "," + str(py))
            dfs(px, py, v, startX, startY)


def solution(rows, columns, queries):
    answer = []

    global arr
    global visited
    arr = [[rows * i + j for j in range(1, columns + 1)] for i in range(0, rows)]
    visited = [[False for j in range(1, columns + 1)] for i in range(0, rows)]

    for q in queries:
        startX = q[0]
        startY = q[1]
        endX = q[2]
        endY = q[3]

        for i in range(startX, endX - 1):
            visited[i][startY - 1] = True
            visited[i][endY - 1] = True

        for j in range(startY - 1, endY):
            visited[startX - 1][j] = True
            visited[endX - 1][j] = True

        dfs(startX - 1, startY + 1, arr[startX - 1][startY + 1], startX - 1, startY - 1)
        print(arr)

    return answer

solution(6,6,[[2,2,5,4]])