q = int(input())
for _ in range(q):
    K, N, A, B = map(int, input().split())
    if B * N >= K:
        print(-1)
    elif A * N < K:
        print(N)
    else:
        print(-((-(K - B * N)) // (A - B))-1)