w = map(int, input().split(','))
v = map(int, input().split(','))
b = int(input())

n = len(w)
dp = [[0 for _ in range(n)] for __ in range(b + 1)]

for i in range(n):
    if w[0] <= i:
        dp[0][i] = v[0]

for i in range(n):
    for j in range(b + 1):
        if w[i] <= j:
            dp[i][j] = max(dp[i - 1][j], v[i] + dp[i - 1][j - w[i]])
        else:
            dp[i][j] = dp[i - 1][j]


print(list(dp))

print(dp[n - 1][b])