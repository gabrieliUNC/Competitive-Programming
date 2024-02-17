from collections import defaultdict

MOD = int(1e9 + 7)
N, W, H = map(int, input().split(' '))
dp = [[0 for _ in range(N + 1)] for _ in range(W + 1)]

squares = min(W * H, N)
plains = (squares // W) + 1

def f(w, ribbon):
    if ribbon < 0:
        return 0
    if w > W:
        return 1
    if dp[w][ribbon]:
        return dp[w][ribbon]
    scenes = 0
    for i in range(H + 1):
        scenes = scenes + f(w + 1, ribbon - i)
    dp[w][ribbon] = scenes % MOD
    return scenes

print((f(1, N) - plains + MOD) % MOD)