m , n = map(int , input().split())
share = []
ll = []
for i in range(n):
     x , y = map(int , input().split())
     ll.append([x , y])
l = (ll[0][0] , ll[0][1])
for i in range(2):
     aa = l[i]
     ans = 0
     bib = [0] * (m + 1)
     for j in ll:
          if j[0] != aa and j[1] != aa:
               bib[j[0]] += 1
               bib[j[1]] += 1
               ans += 1
     if max(bib) == ans:
          print("YES")
          exit()
print("NO")
