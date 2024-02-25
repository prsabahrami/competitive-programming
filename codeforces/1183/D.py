import sys
input = sys.stdin.readline
q = int(input())
for _ in range(q):
    n = int(input())
    a = [int(i) for i in input().split()]
    c = {}
    for i in a:
        if i in c:
            c[i] += 1
        else:
            c[i] = 1
    bib = []
    for i in c:
        bib.append(c[i])
    bib = sorted(bib)[::-1]
    prev = bib[0] + 1
    su = 0
    for i in range(len(bib)):
        ne = min(prev-1, bib[i])
        if ne <= 0:
            break
        su += ne
        prev = ne
    print(su)

