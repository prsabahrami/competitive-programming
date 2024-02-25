#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
 
#define SZ(x)                       (int) x.size()
#define F                           first
#define S                           second
#define lc							id << 1
#define rc 							lc | 1

const ll N = 1e6 + 10;
int n, m, q, A[N], R[N];
pii seg[N << 2]; vector<pii> Q[N];

void leftarm(int id = 1, int l = 0, int r = N) {
	if (r - l == 1) {
		seg[id] = {l, l};
		return;
	}
	int mid = (l + r) >> 1;
	leftarm(lc, l, mid);
	leftarm(rc, mid, r);
	seg[id] = max(seg[rc], seg[lc]);
}

pii rightarm(int ql, int qr, int id = 1, int l = 0, int r = N) {
	if (qr <= l || r <= ql) return {-1e9, -1e9};
	if (ql <= l && r <= qr) return seg[id];
	int mid = (l + r) >> 1;
	return max(rightarm(ql, qr, lc, l, mid), rightarm(ql, qr, rc, mid, r));
}

void middlearm(int pos, int x, int id = 1, int l = 0, int r = N) {
	if (r - l == 1) {
		seg[id].F = x;
		return;
	}
	int mid = (l + r) >> 1;
	if (pos < mid) middlearm(pos, x, lc, l, mid);
	else middlearm(pos, x, rc, mid, r);
	seg[id] = max(seg[lc], seg[rc]);
}


int Find(int x) {
	pii y = rightarm(x, x + 1);
	if (y.F == x) return x;
	pii z = rightarm(x + 1, y.F + 1);
	if (z.F <= y.F) return y.F;
	int w = Find(z.S);
	middlearm(x, w); return w;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int l, r; scanf("%d%d", &l, &r);
		A[r] = l;
	}
	scanf("%d", &q);
	for (int i = 1; i <= q; i++) {
		int l, r; scanf("%d%d", &l, &r);
		Q[r].push_back({l, i});
	}
	leftarm();
	for (int i = 1; i <= n; i++) {
		if (A[i]) middlearm(A[i], i);
		for (pii j : Q[i]) {
			R[j.S] = Find(j.F);
		}
	}
	for (int i = 1; i <= q; i++) printf("%d\n", R[i]);
    return 0;
}

