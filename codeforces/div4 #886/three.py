t = int(input())

while t > 0:
    ans = ""
    i = 0
    while i < 8:
        line = input()
        for char in line:
            if char != '.':
                ans += char
        i += 1
    
    print(ans)


    t -= 1