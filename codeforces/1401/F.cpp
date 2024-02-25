#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;
 
#define SZ(x)                       (ll) x.size()
#define F                           first
#define S                           second
#define lc	 						id << 1
#define rc 							lc | 1

const ll N = 1e6 + 10;
int n, q; ll seg[N << 2], A[N], M[N << 2];

void update(int pos, ll x, int id = 1, int l = 0, int r = 1 << n, int h = n - 1) {
	if (r - l == 1) {
		seg[id] = x;
		return;
	}
	int mid = (l + r) >> 1;
	if (M[h]) {
		if (pos >= mid) update(pos, x, lc, mid, r, h - 1);
		else update(pos, x, rc, l, mid, h - 1);
	} else {
		if (pos < mid) update(pos, x, lc, l, mid, h - 1);
		else update(pos, x, rc, mid, r, h - 1);
	}
	seg[id] = seg[lc] + seg[rc];
}

ll get(int ql, int qr, int id = 1, int l = 0, int r = 1 << n, int h = n - 1) {
	if (qr <= l || r <= ql) return 0;
	if (ql <= l && r <= qr) return seg[id];
	int mid = (l + r) >> 1;
	if (M[h]) return get(ql, qr, lc, mid, r, h - 1) + get(ql, qr, rc, l, mid, h - 1);
	return get(ql, qr, lc, l, mid, h - 1) + get(ql, qr, rc, mid, r, h - 1);
}

int main() {
	scanf("%d%d", &n, &q);
	for (int i = 0; i < 1 << n; i++) {
		int x; scanf("%d", &x);
		update(i, x);
	}
	while (q--) {
		int t, l, r, x, k; scanf("%d", &t);
		if (t == 1) {
			scanf("%d%d", &x, &k);
			update(x - 1, k); 
		} else if (t == 2) {
			scanf("%d", &k);
			for (int i = 0; i < k; i++) M[i] ^= 1;
		} else if (t == 3) {
			scanf("%d", &k);
			M[k] ^= 1;
		} else {
			scanf("%d%d", &l, &r);
			printf("%lld\n", get(l - 1, r));
		}
	}
    return 0;
}

