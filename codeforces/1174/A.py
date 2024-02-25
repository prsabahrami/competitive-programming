n = int(input())
l = [*map(int , input().split())]
l.sort()
if sum(l[:n]) == sum(l[n:]):
     print(-1)
     exit()
print(*l)
