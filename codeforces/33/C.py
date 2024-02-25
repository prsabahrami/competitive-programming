n = int(input())
summ = 0
mx = 0
l = [*map(int ,input().split())]
for i in l:
     summ += i
     if summ < 0:
          summ = 0
     mx = max(summ , mx)
summ = 0
for i in l:
     summ += i
print(2*mx-summ)
