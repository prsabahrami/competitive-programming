n =  int(input())
if n == 1 or n == 2:
     print(n)
     exit()
if n % 2:
     print(n * (n - 1) * (n - 2))
     exit()
if (n % 3):
     print(n * (n - 1) * (n - 3))
     exit()
print((n - 1)* (n - 2) * (n - 3))
