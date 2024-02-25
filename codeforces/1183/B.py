q = int(input())
for i in range(q):
     n , k = map(int ,input().split())
     l = [*map(int ,input().split())]
     mn = min(l)
     mn += k
     f = 1
     for i in l:
          if i != mn - k:
               if i > mn:
                    if i - mn > k:
                         print(-1)
                         f = 0
                         break
                    
               if i < mn:
                    if mn - i > k:
                         mn -= (mn - (i + k))
     if f:
          print(mn)
