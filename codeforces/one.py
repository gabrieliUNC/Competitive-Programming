s = input()
vowels = "aeiou"

one = 0
two = 0

for c in s:
    if c in vowels:
        one += 1
        two += 1
    if c == 'y':
        two += 1

print(f"{one} {two}")