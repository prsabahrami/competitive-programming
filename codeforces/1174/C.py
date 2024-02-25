n = int(input())
t = 1
ans = [0] * (n + 2)
for i in range(2 , n + 1):
     if (ans[i] == 0):
          for j in range(i , n + 1 , i):
               if (ans[j] == 0):
                    ans[j] = t
          t += 1
for i in range(2 , n + 1):
     print(ans[i] , end = " ")
