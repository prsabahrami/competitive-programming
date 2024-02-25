q = int(input())
for i in range(q):
     n = int(input())
     ans = n // 4
     if (n <= 3 or n == 5 or n == 7 or n == 11):
          print(-1)
     else:
          if n % 2:
               ans -= 1
          print(ans)
          
