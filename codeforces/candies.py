t = int(input())

twos = [2**i for i in range(0, 50)]
prefix = [sum(twos[: i + 1]) for i in range(len(twos))]

while t > 0:
    n = int(input())
    for e in prefix:
        if n % e == 0 and e!=1:
            print(int(n / e))
            break
    
    t-=1