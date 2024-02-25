n = int(input())
l = [*map(int , input().split())]
ind = 1 << 60
mini = 0
for i in range(n):
     if l[i] >= 0:
          l[i] = (-l[i]) - 1
     if l[i] < mini:
          mini = l[i]
          ind = i
if (n % 2):
     l[ind] = (-l[ind] - 1)
print(*l)
