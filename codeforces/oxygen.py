list = []
list = input().split(" ")
curr: long = int(list[0])
i = 1
ok = True
while i < len(list):
    curr-=1
    if(curr<=0):
        ok = False
        break
    curr = max(curr, int(list[i]))
    if(curr<=0):
        ok = False
    i+=1

if ok:
    print(1)
else:
    print(0)