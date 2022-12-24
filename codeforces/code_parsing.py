s = input()
first = s.count("x")
second = s.count("y")
if(first==0 or second==0):
    print(s)
else:
    if(first>second):
        i = 0
        temp = ""
        while i < first-second:
            temp+='x'
            i+=1
        print(temp)
    else:
        i = 0
        temp = ""
        while i < second-first:
            temp+='y'
            i+=1
        print(temp)
