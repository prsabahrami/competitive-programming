a , b , c , d = map(int , input().split())
s = [a , b , c]
s.sort()
ans = 0
if(s[1] - s[0]) < d:
     ans += d - (s[1] - s[0])
if (s[2] - s[1]) < d:
     ans += d - (s[2] - s[1])
print(ans)
