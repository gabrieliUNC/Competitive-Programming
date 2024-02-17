from collections import defaultdict
import math
bigassnumber = input()
l = len(bigassnumber)

if l <= 6:
    x = int(bigassnumber)
    ss = 1
    for i in range(1, 100):
        ss *= i 
        if ss == x:
            print(i)
            break
else:

    i = 0
    ss = 0
    for i in range(1, int(2e5) + 7):
        ss += math.log10(i)
        if math.floor(ss) + 1 == l:
            print(i)
            break