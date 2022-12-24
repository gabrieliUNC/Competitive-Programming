t = int(input())
while t>0:
    num = 0
    ans = []
    s = input();
    two = s.count("two")
    while two > 0:
        temp = s.find("two")
        if temp!=-1:
            num+=1
            ans.append(temp+1)
            s = s[:temp+2] + '/' + s[temp+3:]
        two = s.count("two")
    
    one = s.count("one")
    while one > 0:
        temp = s.find("one")
        if temp!=-1:
            num+=1
            ans.append(temp+1)
            s = s[:temp] + '/' + s[temp+1:]
        one = s.count("one")
    
    print(s)
    print(num)
    for e in ans:
        print(e)
    t-=1