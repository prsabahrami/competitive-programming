from heapq import *
N, M = map(int, input().split())
A = [int(a) for a in input().split()]

h = []
s = 0
k = 0
ANS = []
for a in A:
    t = []
    while s + a > M:
        t.append(heappop(h))
        s += t[-1]
    ANS.append(len(t)+k)
    while t:
        s -= t[-1]
        heappush(h, t.pop())
    s += a
    heappush(h, -a)
    if s > M:
        s += heappop(h)
        k += 1
print(*ANS)