import sys
input = sys.stdin.readline
m , s = map(int , input().split())
if s == 0 or s > 9 * m:
     if s == 0 and m == 1:
          print(*[0 , 0])
     else:
          print(*[-1 , -1])
     exit()
res = m * [0]
ress = m * [0]
res[0] = 1
ress[0] = 1
l = 0
r = m - 1
for i in range (1 , s):
     if res[l] == 9:
          l += 1
     res[l] += 1
     if ress[r] == 9:
          r -= 1
     ress[r] += 1

for i in ress:
     print(i , end = "")
print(end = " ")
for i in res:
     print(i , end = "")
