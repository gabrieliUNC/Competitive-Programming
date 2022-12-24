t = int(input())
mapped = [[]]
while t > 0:
    list = input().split(" ")
    ok = False
    for arr in mapped:
        if list[0] in arr:
            ok = True
            arr.append(list[1])
    if not ok:
        mapped.append(list)

    t-=1


print(len(mapped)-1)
for array in mapped:
    i = 0
    temp = ""
    while i < len(array):
        if i==0:
            temp+=(array[i])
            temp+=(" ")
        if i==len(array)-1:
            temp+=(array[i])
        i+=1
    print(temp)

