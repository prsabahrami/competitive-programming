n , m = map(int  , input().split())
k = n // (2 * m)
if (n % (2 * m) != 0):
    k += 1
if m > n:
    print(-1)
else:
    print(k * m)