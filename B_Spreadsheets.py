

def i_to_letters(num: int):
    s = ""

    while(num > 0):
        tmp = int((num - 1) % 26)
        if tmp < 0:
            tmp += 26
        s += chr(tmp + ord('A'))
        num //= 26
        
    
    s = s[::-1]
    return s


def letters_to_i(letters: str):
    num, n = 0, len(letters)

    for i in range(n - 1, - 1, -1):
        num += pow(26, n - (i + 1)) * ((ord(letters[i]) - ord('A')) + 1)

    
    return num

tt = int(input())

while tt > 0:
    s = input()
    try:
        if s[0] == 'R' and '1' <= s[1] <= '9':
            i, num = 1, 0
            while s[i] != 'C':
                num = num * 10 + int(s[i])
                i += 1
            
            row = num

            i += 1
            num = 0
            while(i < len(s)):
                num = num * 10 + int(s[i])
                i += 1
            
            col = i_to_letters(num);

            print(col + str(row))


        else:
            i = 0 
            letters = ""
            while(not s[i].isdigit()):
                letters += s[i]
                i += 1

            col = letters_to_i(letters)

            num = 0
            while(i < len(s)):
                num = num * 10 + int(s[i])
                i += 1

            print("R" + str(num) + "C" + str(col))
    except Exception:
        print('Exception: ' + s)

    tt -= 1    