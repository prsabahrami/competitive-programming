n , x = map(int,input().split())
mark = [0 for x in range(1 << 18 +1)]
mark[x] = 1
cur = 0
MAXN = 1 << n
ans = []
for i in range(1 , MAXN):
    if i != x:
        res = i ^ x
        if mark[i] == 0:
            ans.append(i^cur)
            mark[res] = 1
            mark[i] = 1
            cur = i
print(len(ans))
print(*ans)
