def getsum(x):
     summ = 0
     while x:
          summ += x % 10
          x //= 10
     return summ
     
n = int(input())
t = int(n ** .5)
if t < 5000:
     s = 1
else:
     s = t - 5000
for i in range(s , t + 1):
     if n % i == 0:
          if (getsum(i) + i == n // i):
               print(i)
               exit()
print(-1)
exit()
