def unique(sequence):
    seen = set()
    return [x for x in sequence if not (x in seen or seen.add(x))]

t = int(input())
i = 0
while i < t:
    n = int(input())
    s = input().lower()
    ans = unique(s)
    print(ans)
    if ans == ['m', 'e', 'o', 'w']:
        print("YES");
    else:
        print("NO")
    i += 1 