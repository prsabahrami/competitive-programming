def jam(n):
     ans = 0
     for i in str(n):
          ans += int(i)
     return ans
n = int(input())
for i in range(n , 2000):
     if jam(i) % 4 == 0:
          print(i)
          exit()
