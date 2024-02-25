s = input()
def chk(ss):
     global s
     ll = -1
     for i in ss:
          ll = s.find(i , ll + 1)
          #print(ll)
          if ll < 0 :
               return 0
     return 1
for i in range(0 , 1001 , 8):
     if chk(str(i)):
          print("YES")
          print(i)
          exit()
print("NO")
