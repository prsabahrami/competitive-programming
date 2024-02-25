#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;
 
#define SZ(x)                       (ll) x.size()
#define F                           first
#define S                           second
#define lc 							id << 1
#define rc 							lc | 1

const ll N = 1e6 + 10;
int seg[N << 2], dp[2][N], n;
char S[N];

void build(int id = 1, int l = 1, int r = n + 1) {
	if (r - l == 1) {
		seg[id] = max(dp[0][l], dp[1][l]);
		return;
	}
	int mid = (l + r) >> 1;
	build(lc, l, mid);
	build(rc, mid, r);
	seg[id] = max(seg[lc], seg[rc]);
}

int get(int ql, int qr, int x, int id = 1, int l = 1, int r = n + 1) {
	if (seg[id] < x || qr <= l || r <= ql || qr <= ql) return -1;
	if (r - l == 1) return l;
	int mid = (l + r) >> 1, res;
	res = get(ql, qr, x, lc, l, mid);
	if (res == -1) res = get(ql, qr, x, rc, mid, r);
	return res;
}

int main() {
	scanf("%d%s", &n, S + 1);
	for (int i = 1; i <= n; i++) {
		dp[1][i] = dp[1][i - 1], dp[0][i] = dp[0][i - 1];
		if (S[i] == '1') dp[1][i]++, dp[0][i] = 0;
		if (S[i] == '0') dp[0][i]++, dp[1][i] = 0;
		if (S[i] == '?') dp[1][i]++, dp[0][i]++;
	}
	build();
	for (int i = 1; i <= n; i++) {
		int ptr = 0, ans = 0;
		while (ptr != -1) {
			ptr = get(ptr + i, n + 1, i);
			ans++;
		}
		printf("%d ", ans - 1);
	}
    return 0;
}

