n = int(input())
print(n // 2 + 1)
while n:
    k = n // 2 + 1
    n -= 1
    print(k , k - n % 2)