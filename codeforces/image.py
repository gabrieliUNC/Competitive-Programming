t = int(input())
while t > 0:
    x = input()
    y = input()
    x += y
    print(len(set(x)) - 1)
    t-=1