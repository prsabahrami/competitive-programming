n = int(input())
dict = {}
ans = []
for i in range(n):
     s = input()
     if s not in ans:
          print('OK')
          ans.append(s)
          dict[s] = 1
     else:
          print(s + str(dict[s]))
          dict[s] += 1
