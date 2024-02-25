s1 = input()
s2 = input()
ans = 0
tot = 0
for i in range(len(s2)):
     tot += s1[i] != s2[i]
ans += tot % 2 == 0
for i in range(len(s2) , len(s1)):
     tot += s1[i] != s1[i - len(s2)]
     ans += tot % 2 == 0
print(ans)
