i = 0
ans = 0
while(i<4):
    inp = input()
    if("true" in inp):
        ans+=1
    i+=1
if ans>2:
    print("Wait for the storm to pass.")
else:
    print("Go fishing!")