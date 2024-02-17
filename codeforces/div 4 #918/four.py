t = int(input())
vowels = "ae"
consonants = 'bcd'

def isSyllable(s):
    n = len(s)
    if n != 2 and n != 3:
        return False
    if n == 2:
        if s[1] in vowels and s[0] in consonants:
            return True
        return False
    if s[0] in consonants and s[1] in vowels and s[2] in consonants:
        return True
    return False

for _ in range(t):
    n = int(input())
    s = input()
    pos = [0 for __ in range(n)]
    sz = 0
    prev = 0

    for i in range(2, n):
        if isSyllable(s[prev:i]) and (isSyllable(s[i: i + 2]) or isSyllable(s[i: i + 3])):
            pos[i] = 1
            sz += 1
            prev = i
        elif isSyllable(s[prev:i + 1]) and (isSyllable(s[i + 1: i + 3]) or isSyllable(s[i + 1: i + 4])):
            pos[i + 1] = 1
            sz += 1
            prev = i + 1

    delta = 0
    ans = ['.' for _ in range(n + sz)]
    for i in range(n):
        if pos[i] == 1:
            delta += 1

        ans[i + delta] = s[i]
    ans = ''.join(ans)

    print(ans)