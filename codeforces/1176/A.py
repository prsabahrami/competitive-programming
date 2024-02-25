q = int(input())
def bib(n):
     cnt = 0
     while n > 1:
          if n % 5 and n % 3 and n % 2:
               return -1
          if n % 2 == 0:
               n //= 2
               cnt += 1
          if n % 3 == 0:
               n //= 3
               n *= 2
               cnt += 1
          if n % 5 == 0:
               n //= 5
               n *= 4
               cnt += 1
     return cnt
for i in range(q):
     print(bib(int(input())))
