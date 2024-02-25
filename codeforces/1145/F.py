ll = ['A','E','F','H','I','K','L','M','N','T','V','W','X','Y','Z']
s = input()
f1 = 0
f2 = 0
for i in range(len(s)):
     f1 = 0
     for j in range(15):
          if (s[i] == ll[j]):
               f1 = 1
               if (not(i)):
                    f2 = 1
               else:
                    if (not(f2)):
                         print("NO")
                         exit()
     if(not(f1)):
          if(not(i)):
               f2 = 0
          else:
               if(f2):
                    print("NO")
                    exit()
print("YES")
