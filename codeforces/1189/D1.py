n = int(input())
l = [0] * n
for i in range(n - 1):
     u , v = map(int , input().split())
     l[u - 1] += 1
     l[v - 1] += 1
for i in l:
     if i == 2:
          print("NO")
          exit()
print("YES")
