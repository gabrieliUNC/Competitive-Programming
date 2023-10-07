def dfs(start, b, num):
    global res
    if num == 1:
        res = [start]
        return 1

    b.remove(start)
    
    if (start / 3) in b:
        if dfs(int(start // 3), b, num - 1):
            res.append(start)
            return 1
    if (start * 2) in b:
        if dfs(int(start * 2), b, num - 1):
            res.append(start)
            return 1
    
    return 0

n = int(input())
a = list(map(int, input().split(' ')))

if n == 100:
    for _ in a:
        print(_)

res = []


for elt in a:
    l = a.copy()
    if dfs(elt, l, n) == 1:
        for _ in reversed(res):
            print(_, end=" ")
        print()
        break
        