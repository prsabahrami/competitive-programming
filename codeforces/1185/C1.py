N, M = map(int, input().split())
A = [int(a) for a in input().split()]
ANS = []
X = []
t = 0
for i in range(N):
    tt = t
    j = 0
    while A[i] > M - tt:
        tt -= X[j]
        j += 1
    ANS.append(j)
    X = sorted(X+[A[i]])[::-1]
    t += A[i]

print(*ANS)