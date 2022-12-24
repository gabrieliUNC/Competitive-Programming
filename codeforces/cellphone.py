n = int(input())
num = input()


ok = True
okay = True
wow = True
woww = True

if ('0' in num) and ('1' in num or '2' in num or '3' in num):
    print("YES")

    
else:
    if '0' not in num:
        for i in num:
            if int(i)-1<=0:
                wow = False
        for i in num:
            if int(i)+1>9:
                woww = False
    else:
        wow = False
        woww = False

    for i in num:
        if int(i)!=0 and int(i)-3<0:
            ok = False

    for i in num:
        if int(i) != 8 and int(i)+3>9:
            okay = False

    if ok or okay or wow or woww:
        print("NO")

    else:
        print("YES")