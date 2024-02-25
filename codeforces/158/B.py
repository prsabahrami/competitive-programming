cnt = [0] * 4
n = int(input())
l = [*map(int ,input().split())]
for i in l:
     cnt[i - 1] += 1
tot = cnt[3] + cnt[2] + cnt[1] // 2
cnt[0] -= cnt[2]
if (cnt[1] % 2 == 1):

     tot += 1
     cnt[0] -= 2
if (cnt[0] > 0):
     tot += (cnt[0] + 3) // 4
print(tot)
