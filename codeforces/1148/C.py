n = int(input())
l = [*map(int, input().split())]
l = [i - 1 for i in l]
pos = {}
ans = []
for i, j in enumerate(l):
	pos[j] = i
def swap(i, j):
	ans.append((pos[l[i]] + 1, pos[l[j]] + 1))
	pos[l[i]], pos[l[j]] = pos[l[j]], pos[l[i]]
	l[i], l[j] = l[j], l[i]
def solve(i):
	u = n - 1 if pos[i] < n // 2 else 0
	v = 0 if pos[i] < n // 2 else n - 1
	swap(pos[i], u)
	if abs(u - i) * 2 >= n:
		swap(u, i)
	else:
		swap(u, v)
		swap(v, i)
for i in range(1, n - 1):
	if l[i] != i:
		solve(i)
if l[0] != 0:
	swap(0, n - 1)
print(len(ans))
print('\n'.join([' '.join(map(str, [*i])) for i in ans]))
