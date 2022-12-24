test_cases: int = int(input())
while test_cases>0:
    size: int = int(input())
    q_and_a: str = input()
    curr = 0
    ok = True
    while(size>0):
        curr = curr-1 if q_and_a[size-1]=='Q' else curr+1
        if(curr<0):
            print("No")
            ok = False
            break
        size-=1
    if ok:
        print("Yes")
    test_cases-=1