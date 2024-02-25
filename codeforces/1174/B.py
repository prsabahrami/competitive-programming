n = int(input())
l = [*map(int , input().split())]
a = [0 , 0]
for i in l:
     if (i % 2):
          a[0] = 1
     else:
          a[1] = 1
if (a[0] and a[1]):
     print(*sorted(l))
     exit()
print(*l)
     
