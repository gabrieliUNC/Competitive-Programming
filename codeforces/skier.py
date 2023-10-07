def direction(s):
    if s == 'N':
        return [0, 1]
    if s == 'S':
        return [0, -1]
    if s == 'W':
        return [-1, 0]
    if s == 'E':
        return [1, 0]

t = int(input())

for _ in range(t):
    inp = input()
    s = set()
    ans = 0
    coord = [0, 0]

    for c in inp:
        move = direction(c)
        curr = coord

        curr[0] += move[0]
        curr[1] += move[1]

        w = tuple((min(curr, coord)), (max(curr, coord)))

        if tuple(w) in s:
            ans += 1
        else:
            ans += 5

        s.add(w)
        coord = curr
        
    print(ans)
                

