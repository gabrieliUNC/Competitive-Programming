for _ in range(int(input())):
    n,c=map(int,input().split())
    s=list(map(int,input().split()))
    l=0
    r=10**10
    while r-l>1:
        mid=(r+l)//2
        temp=0
        for i in s:
            temp+=(i+2*mid)**2
        if temp<=c:
            l=mid
        else:
            r=mid
    print(l)