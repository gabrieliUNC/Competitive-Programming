s = input()


ans = 1
freq = {}
for c in s:
    if c in freq:
        freq[c]+=1
    else:
        freq[c]=1

for i in freq:
    ans*=freq[i]
print(ans)