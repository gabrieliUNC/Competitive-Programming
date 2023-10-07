def solve():
    board = [input() for j in range(3)]

    for x in range(3):
        if board[x][0] == '.' or board[x][1] == '.' or board[x][2] == '.':
            continue
        if board[x][0] == board[x][1] == board[x][2]:
            print(board[x][0])
            return
    for y in range(3):
        if board[0][y] == '.' or board[1][y] == '.' or board[2][y] == '.':
            continue
        if board[0][y] == board[1][y] == board[2][y]:
            print(board[0][y])
            return
    if board[0][0] == board[1][1] == board[2][2]:
        if board[0][0] != '.':
            print(board[0][0])
            return
    if board[0][2] == board[1][1] == board[2][0]:
        if board[0][2] != '.':
            print(board[0][2])
            return
    print("DRAW")
    return

t = int(input())
for i in range(t):
    solve()