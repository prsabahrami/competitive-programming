d , sumtime = map(int, input().split())
summin = 0
summax = 0
mint = []
maxt = []
ans = 0
for i in range(d):
     u , v = map(int , input().split())
     summin += u
     summax += v
     mint.append(u)
     maxt.append(v)
if sumtime > summax or sumtime < summin:
     print("NO")
     exit()
req = sumtime - summin
bib = [0] * d
i = 0
while req > 0 and i < d:
     if (maxt[i] - mint[i]) > req:
          bib[i] += req
          req = 0
          break
     req -= (maxt[i] - mint[i])
     bib[i] += (maxt[i] - mint[i])
     i += 1
print("YES")
for i in range(d):
     print(mint[i] + bib[i] ,end = " ")
