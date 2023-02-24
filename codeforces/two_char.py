n = int(input())
 
words = []
 
for i in range(n):
    s = input()
    if len(set(s)) <= 2:
        temp = []
        for word in words:
            if (set(s) <= set(word)) or ((len(set(word)) == 1) and (len(set(s)) == 1)):
                temp.append(word + s)
        for item in temp:
            words.append(item)
        words.append(s)
 
if(len(words) > 0): print(len(sorted(words, key = len, reverse=True)[0]))
else: print(0)