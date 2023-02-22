entrances = []
global dots
dots = 0
inp = input().split()
x = int(inp[0])
y = int(inp[1])

v = [[0 for col in range(0, y)] for row in range(0, x)]

arr = [[c for c in input()] for i in range(0, x)]
i = 0
while i < x:
    j = 0
    while j < y:
        if (arr[i][j] == '.'):
            dots += 1
        elif (arr[i][j] != ' ') and (arr[i][j] != 'X'):
            entrances.append((i, j)) 
        j += 1
    i += 1


found = 0


def dfs(arr, i, j, v, x, y):
    if(v[i][j] == 1): return
    if(arr[i][j] == '.'): 
        global dots
        dots -= 1
    v[i][j] = 1;
    if(i + 1 < x and (arr[i + 1][j] == ' ' or arr[i + 1][j] == '.')): dfs(arr, i + 1, j, v, x, y)
    if(i - 1 >= 0 and (arr[i - 1][j] == ' ' or arr[i - 1][j] == '.')): dfs(arr, i - 1, j, v, x, y)
    if(j + 1 < y and (arr[i][j + 1] == ' ' or arr[i][j + 1] == '.')): dfs(arr, i, j + 1, v, x, y)
    if(j - 1 >= 0 and (arr[i][j - 1] == ' ' or arr[i][j - 1] == '.')): dfs(arr, i, j - 1, v, x, y)
    return;


if len(entrances) > 0:
    for a, b in entrances:
        CURR = dots
        if dots > 0:
            dfs(arr, a, b, v, x, y)
        else:
            break
        if CURR != dots:
            found += 1

print(f"{found} {dots}\n")