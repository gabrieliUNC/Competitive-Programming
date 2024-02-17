n, t = list(map(int, input().split()))

bids = [["", 0] for __ in range(n)]

for i in range(n):
    bids[i][0], bids[i][1] = input().split()
    bids[i][1] = int(bids[i][1])

bids.sort(key= lambda x: x[1], reverse=True)

ans = []

for name, num in bids:
    if t >= num:
        t -= num
        ans.append(name)

if t != 0:
    print("0")

else:
    print(len(ans))
    for name in ans:
        print(name)
    