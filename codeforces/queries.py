import bisect
input()

a = sorted(list(map(int, input().split(' '))))
b = list(map(int, input().split(' ')))

for elt in b:
    print(bisect.bisect(a, elt), end=" ")
print()