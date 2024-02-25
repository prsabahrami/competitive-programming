q = int(input())
for i in range(q):
     n , k = map(int , input().split())
     ans = 0
     while n != 0:
          ans += n % k
          n -= n % k
          if n == 0:
               break
          while n % k == 0:
               n //= k
               ans += 1
     print(ans)
          
