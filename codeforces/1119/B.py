n , h = map(int , input().split())
l = [*map(int , input().split())]
k = 0
while h >= sum(sorted(l[:k + 1])[-1::-2]) and k < n:
     k += 1
print(k)
