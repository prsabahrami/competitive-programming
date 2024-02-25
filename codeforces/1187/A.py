q = int(input())
for _ in range(q):
    n , s , t = map(int , input().split())
    bib1 = n - s
    bib2 = n - t
    print(max(bib1 , bib2) + 1)