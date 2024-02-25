import sys
input = sys.stdin.readline
n = int(input())
l = [*map(int ,input().split())]
ans = []
for i in range(n - 1):
     m = min(l[i:])
     ind = l.index(m , i)
     if ind != i:
          ans.append([ind , i])
          l[ind] , l[i] = l[i] , l[ind]
print(len(ans))
for i in ans:
     print(*i)
