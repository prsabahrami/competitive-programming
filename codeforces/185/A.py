MOD = 1000000007
def bib(x, y):
	ans = 1
	x = x % MOD
	while y > 0:
		if (y & 1 != 0): ans = (ans * x) % MOD
		y = y >> 1
		x = (x * x) % MOD
	return ans % MOD
n = int(input())

ans = bib(2, 2 * n - 1) + bib(2, n - 1)
if (n == 0): print(1)
else: print(ans % MOD)