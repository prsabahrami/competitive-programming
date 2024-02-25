n = int(input())
s = input()
one = s.count('1')
zero = s.count('0')
if one != zero:
     print(1)
     print(s)
else:
     print(2)
     print(s[0] , s[1:])
