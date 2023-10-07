a = list(map(int, input().split()))
n = len(a)

r_a = []
r_a[n - 1] = a[n - 1]

for _ in range(n - 2, -1, -1):
    r_a[_] = max(r_a[_ + 1], a[_])

l, r = 0, 1
ans = [-1, -1]

while l < n and r < n and l < r:
    if r_a[r] > a[r]:
        r += 1
    else:
        l += 1
    