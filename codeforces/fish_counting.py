list = {"halibut": 0, "mackerel": 0, "salmon": 0, "snapper": 0, "squid": 0, "tuna": 0}
inp = input()

for key in list.keys():
    res = [False for i in range(len(inp))]
    i = 0
    ok = True
    while i < len(inp):
        if key[i] in inp:
            res[i] = True
        else:
            ok = False
            break
        i+=1
    if ok:
        list[key]+=1
        i = 0
        nxt = ""
        while i < len(inp):
            if(res[i]):
                continue
            else:
                nxt += inp[i]
            i+=1
        inp = nxt
print(list)