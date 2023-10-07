a = list(map(int, input().split()))
n = len(a)

for i in range(n):
    if a[abs(a[i])] < 0:
        print(abs(a[i]))
    else:
        a[abs(a[i])] *= -1

