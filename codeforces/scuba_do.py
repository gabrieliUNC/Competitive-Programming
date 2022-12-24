inp: dict[str, int] = {}
keys = input().split(", ")
values = input().split(", ")
i = 0
while i < len(keys):
    inp[keys[i]] = int(values[i])
    i+=1

ans = []
p = int(input())
i = 0
while(i<p):
    point = input()
    temp: dict[str, int] = {}
    keys = input().split(", ")
    values = input().split(", ")
    j = 0
    while j < len(keys):
        temp[keys[j]] = int(values[j])
        j+=1
    
    ok = True
    for key in temp.keys():
        if key not in inp.keys():
            ok = False
            break
        else:
            if temp[key] > inp[key]:
                ok = False
                break

    if(ok):
        ans.append(point)
    i+=1
ans.sort()
for thing in ans:
    print(thing)