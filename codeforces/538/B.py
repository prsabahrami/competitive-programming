n = int(input())
m = 0
aa = [0] * 10005
t = 1
while n:
     x = n % 10
     m = max(m , x)
     for i in range(x):
          aa[i] += t
     t *= 10
     n //= 10
print(m)
for i in range(m):
     print(aa[i] , end = " ")
