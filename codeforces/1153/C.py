n = int(input())
s = list(input())
if n % 2:
     print(":(")
     exit()
res = n // 2
for i in range(n):
     if (s[i] == '('): res -= 1
for i in range(n):
     if (s[i] != '?'): continue
     if (res > 0) :
          s[i] = '('
          res -= 1
     else:
          s[i] = ')'
c = 0
for i in range(n):
     if (s[i] == '(') :c += 1
     else : c -= 1
     if (c < 0 or (i < n - 1 and c == 0)):
          print(":(")
          exit()
if (c): print(":(")
else :
     print("".join(s))
