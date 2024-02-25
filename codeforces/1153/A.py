import sys
input = sys.stdin.readline
n , t = map(int ,input().split())
ans = 1 << 60
l = []
for i in range(n):
     s , d = map(int , input().split())
     if s < t:
          s = (t - s + d - 1) // d * d + s
     l.append([s , i + 1])

l.sort()
print(l[0][1])
