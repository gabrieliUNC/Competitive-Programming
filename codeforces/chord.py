dp = ["C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "B", "H"]

t: list[str] = input().split(" ")
cnt: list[int] = []

i = 0
while i < 3:
    j = 0
    while j < 12:
        if t[i] == dp[j]:
            cnt.append(j)
        j+=1
    i+=1

cnt.sort()
if cnt[1]-cnt[0]==3 and cnt[2]-cnt[1]==4:
    print("minor")

if cnt[1]-cnt[0]==4 and cnt[2]-cnt[1]==3:
    print("major")

for item in cnt:
    print(item)