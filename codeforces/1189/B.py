n = int(input())
l = [*map(int , input().split())]
l.sort()
if l[-1] >= l[-2] + l[-3]:
     print("NO")
else:
     print("YES")
     print(l[-2] , l[-1] , l[-3] , end = " ")
     for i in range(n - 3):
          print(l[i] , end = " ")
