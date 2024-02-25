n = int(input())
l = []
for _ in range(n):
     a , b = map(int ,input().split())
     l.append([a , b])
l.sort()
ans = -1
for i in range(n):
     if ans <= l[i][1]:
          ans = l[i][1]
     else:
          ans = l[i][0]
print(ans)
