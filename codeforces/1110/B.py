n , m , k = map(int ,input().split())
a = [*map(int ,input().split())]
b = []
for i in range(n - 1):
     b.append(a[i + 1] - a[i])
b.sort()
ans = 0
for i in range(n - k):
     ans += b[i]
print(ans + k)
