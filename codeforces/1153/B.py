n , m, h = map(int ,input().split())
a = [*map(int , input().split())]
b = [*map(int ,input().split())]
l = []
for i in range(n):
     l.append([*map(int ,input().split())])
for i in range(n):
     for j in range(m):
          l[i][j] *= min(a[j] , b[i])
          print(l[i][j] , end = " ")
     print()
     
