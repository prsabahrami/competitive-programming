#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
 
#define SZ(x)                       (int) x.size()
#define F                           first
#define S                           second
#define lc 							id << 1
#define rc 							lc | 1

const ll N = 1e5 + 10;
int X, n, m, A[N];
struct Node {
	ll a; int l, r, f; vector<pii> prf, sff;

	friend Node operator+(Node x, Node y) {
		if (x.f) return y;
		if (y.f) return x;
		Node z; z.a = x.a + y.a; z.l = x.l, z.r = y.r; z.f = 0;
		z.prf = x.prf;
		for (pii &oth : y.prf) {
			if ((oth.S | z.prf.back().S) == z.prf.back().S) { z.prf.back().F += oth.F; continue; }
			z.prf.push_back({oth.F, oth.S | z.prf.back().S});
		}
		z.sff = y.sff;
		for (pii &oth : x.sff) {
			if ((oth.S | z.sff.back().S) == z.sff.back().S) { z.sff.back().F += oth.F; continue; }
			z.sff.push_back({oth.F, oth.S | z.sff.back().S});
		}
		int ptr = 0, sum = 0;
		for (int i = SZ(x.sff) - 1; ~i; i--) {
			pii w = x.sff[i];
			while (ptr < SZ(y.prf) && (w.S | y.prf[ptr].S) < X) sum += y.prf[ptr].F, ptr++;
			z.a += 1ll * w.F * (y.r - y.l - sum);
		}
		return z;
	}

};
Node seg[N << 2];

void build(int id = 1, int l = 1, int r = n + 1) {
	if (r - l == 1) {
		tie(seg[id].l, seg[id].r) = {l, r};
		seg[id].a = (X <= A[l]); seg[id].f = 0;
		seg[id].prf = seg[id].sff = {{1, A[l]}};
		return;
	}
	int mid = (l + r) >> 1;
	build(lc, l, mid);
	build(rc, mid, r);
	seg[id] = seg[lc] + seg[rc];
	//printf("%d %lld %lld %lld\n", id, seg[id].a, seg[lc].a, seg[rc].a);
}

void modify(int pos, int x, int id = 1, int l = 1, int r = n + 1) {
	if (r - l == 1) {
		seg[id].prf = seg[id].sff = {{1, x}};
		seg[id].a = (X <= x);
		return;
	}
	int mid = (l + r) >> 1;
	if (pos < mid) modify(pos, x, lc, l, mid);
	else modify(pos, x, rc, mid, r);
	seg[id] = seg[lc] + seg[rc];
}

Node get(int ql, int qr, int id = 1, int l = 1, int r = n + 1) {
	if (qr <= l || r <= ql) return Node{0, 0, 0, 1, {}, {}};
	if (ql <= l && r <= qr) return seg[id];
	int mid = (l + r) >> 1;
	return get(ql, qr, lc, l, mid) + get(ql, qr, rc, mid, r);
}

int main() {
	scanf("%d%d%d", &n, &m, &X);
	for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
	build();/*
	printf("%lld\n", seg[1].a);
	for (auto[x, y] : seg[1].prf) {
		printf("prf %d %d\n", x, y);
	}
	for (auto[x, y] : seg[1].sff) {
		printf("sff %d %d\n", x, y);
	}
	*/
	while (m--) {
		int t, l, r; scanf("%d%d%d", &t, &l, &r);
		if (t == 1) {
			modify(l, r);
		} else {
			printf("%lld\n", get(l, r + 1).a);
		}
	}
    return 0;
}

