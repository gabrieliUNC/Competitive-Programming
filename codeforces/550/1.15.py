from heapq import heappush, heappop
from bisect import bisect, insort

a = list(map(int, input.split()))
n = len(a)

s, x, ans = [], [], 0

for i, v in enumerate(a):
    s.heappush(v, i)

while s:
    v, i = s.heappop()

    y = bisect(x, i)

    ans += i - y

    insort(x, i)


print(ans)
