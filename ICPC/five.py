entrances = {}
dots = 0
inp = input().split()
x = int(inp[0])
y = int(inp[1])
arr = ['0'*x]*y
v = [[0]*x]*y

i = 0
j = 0

while i < x:
    s = input()
    j = 0
    for c in s:
        arr[i][j] = c
        if c == '.':
            dots += 1
        elif c != 'X' and c != ' ':
            entrances.append(i, j)
        j += 1

    i += 1

found = 0


def dfs(arr, i, j, dots, v, x, y):
    if(v[i][j] == 1): return
    if(arr[i][j] == '.'): dots-=1
    v[i][j] = 1;
    if(i + 1 < y and (arr[i + 1][j] == ' ' or a[i + 1][j] == '.')): dfs(a, i + 1, j, dots, v, x, y)
    if(i - 1 >= 0 and (arr[i - 1][j] == ' ' or a[i - 1][j] == '.')): dfs(a, i - 1, j, dots, v, x, y)
    if(j + 1 < x and (arr[i][j + 1] == ' ' or a[i][j + 1] == '.')): dfs(a, i, j + 1, dots, v, x, y)
    if(j - 1 >= 0 and (arr[i][j - 1] == ' ' or a[i][j - 1] == '.')): dfs(a, i, j - 1, dots, v, x, y)
    return;




for p in entrances:
    curr = dots
    if dots > 0:
        dfs(arr, p.first, p.second, dots, v, x, y)
    else:
        break
    if curr != dots:
        found += 1
