n = int(input())
l = [int(i) for i in input().split()]
dp = [0] * (n + 1)
for i in range(n):
  dp[i + 1] = dp[i] + l[i]
q = int(input())
for i in range(q):
  l , r = map(int,input().split())
  print((dp[r] - dp[l - 1]) // 10)
