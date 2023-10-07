
s = input()
x = s.find('.')
if int(s[x - 1]) == 9: print("GOTO Vasilisa.")
elif int(s[x + 1]) < 5: print(s[0:x])
else: print(s[0:x - 1] + str(int(s[x - 1]) + 1))