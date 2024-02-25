q = int(input())
for i in range(q):
     n = int(input())
     l = [*map(int ,input().split())]
     l1 = []
     l2 = []
     l3 = []
     for i in l:
          if (i % 3) == 0:
               l3.append(i)
          if i % 3 == 1:
               l1.append(i)
          if i % 3 == 2:
               l2.append(i)
     cnt = len(l3)
     cnt += min(len(l2) , len(l1))
     cnt += abs(len(l1) - len(l2)) // 3
     print(cnt)
