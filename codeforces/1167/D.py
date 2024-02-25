input()
s = input()
ans = ""
cnt1 = 0
cnt2 = 0
for i in s:
     if i == ')':
          if cnt2 % 2:
               ans += '1'
          else:
               ans += '0'
          cnt2 += 1
     else:
          if cnt1 % 2:
               ans += '1'
          else:
               ans += '0'
          cnt1 += 1
print(ans)
