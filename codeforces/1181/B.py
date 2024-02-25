n = int(input())
s = input()
mid = len(s) // 2
l= mid
r= mid + 1
while l >= 0 and s[l] == '0':
    l -= 1
while r < n and s[r] == '0':
    r += 1
if l == 0:
    print(int(s[:r]) + int(s[r:]))
elif r == n:
    print(int(s[:l]) + int(s[l:]))
else:
    print(min(int(s[:r]) + int(s[r:]) , int(s[:l]) + int(s[l:])))
    