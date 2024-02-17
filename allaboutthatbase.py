from collections import defaultdict
tt = int(input())

mp = defaultdict()
LIMIT = 2 ** 32 - 1
INF = 2 ** 64


for i in range(10, 36):
    c = chr(ord('a') + i - 10)
    mp[c] = i
    mp[i] = c

mp[36] = 0

def ret(f, s, a, op):
    if op == '+':
        return f + s == a
    if op == '-':
        return f - s == a
    if op == '/':
        return f / s == a
    if op == '*':
        return f * s == a

def calc(expression):
    res = []
    first, op, second, ans = expression[0], expression[1], expression[2], expression[-1]
    for radix in range(1, 37):
        f, s, a = base(first, radix), base(second, radix), base(ans, radix)
        if 1 <= f <= LIMIT and 1 <= s <= LIMIT and 1 <= a <= LIMIT:
            if ret(f, s, a, op):
                if radix in mp:
                    res.append(mp[radix])
                else:
                    res.append(radix)
    return res
            
    

def base(num, radix):
    n = len(num) - 1
    res = 0
    for pos in range(n, -1, -1):
        digit = num[pos]
        if digit in mp:
            digit = mp[digit]
        digit = int(digit)
        if digit > radix or (digit == radix and radix != 1) or (radix == 1 and digit == 0):
            return INF
        res += pow(radix, n - pos) * digit
    return res


def solve():
    expression = input().strip().split()
    return calc(expression)




for _ in range(tt):
    ans = solve() 
    if ans == []:
        print('invalid')
    else:
        res = ''
        for b in ans:
            res += str(b)
        print(res)