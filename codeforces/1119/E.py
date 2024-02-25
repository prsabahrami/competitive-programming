n = int(input())
l = [*map(int ,input().split())]
ans = 0
p = 0
for i in range(n - 1 , -1, -1):
     p += l[i] // 2
     if(l[i] % 2 and p > 0):
          ans += 1
          p -= 1
ans += 2 * p // 3
print(ans)
