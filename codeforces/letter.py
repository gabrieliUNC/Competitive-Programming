s = input()
upper = sum(1 for c in s if c.isupper())
lower = len(s)-upper
sub = 0
i = 0
while i < len(s) and s[i].isupper():
    sub+=1
    i+=1
upper-=sub;
sub = 0;
i = len(s)-1
while i>=0 and s[i].islower():
    sub+=1
    i-=1
lower -=sub

ans = upper if upper < lower else lower
print(ans)
