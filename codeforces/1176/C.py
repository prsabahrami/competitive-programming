n = int(input())
l = [*map(int ,input().split())]
mark = [0] * 6
for i in l:
     if i == 4:
          mark[0] += 1
     elif i == 8 and mark[0] > 0:
          mark[1] += 1
          mark[0] -= 1
     elif i == 15 and mark[1] > 0:
          mark[2] += 1
          mark[1] -=1
     elif i == 16 and mark[2] > 0:
          mark[3] += 1
          mark[2] -= 1
     elif i == 23 and mark[3] > 0:
          mark[4] += 1
          mark[3] -= 1
     elif i == 42 and mark[4] > 0:
          mark[5] += 1
          mark[4] -= 1
print(n - mark[5] * 6)
