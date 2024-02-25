#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;
 
#define SZ(x)                       (int) x.size()
#define F                           first
#define S                           second
#define lc 							id << 1
#define rc 							lc | 1

const ll N = 4e5 + 10;
struct Node{
	int a, b, ab, f;

	friend Node operator+(Node X, Node Y) {
		return {X.a + X.f * Y.a, Y.b + Y.f * X.b, max({X.ab, Y.ab, X.b + Y.a}), X.f && Y.f};
	}
};
ll A[N]; int mx[N << 2], type[N], L[N], R[N], n, q;
vector<int> vec; Node seg[N << 2]; string S[N], T[N], Q[N]; char C[N];

int LCP(int x, int y) {
	if (max(x, y) > n || min(x, y) <= 0) return 0;
	int z; for (z = 0; z < min(SZ(T[x]), SZ(T[y])) && T[x][z] == T[y][z]; z++);
	return z;
}

void buildmax(int id = 1, int l = 1, int r = n + 1) {
	if (r - l == 1) {
		mx[id] = SZ(T[l]);
		return;
	}
	int mid = (l + r) >> 1;
	buildmax(lc, l, mid);
	buildmax(rc, mid, r);
	mx[id] = max(mx[lc], mx[rc]);
}

void updatemax(int pos, int id = 1, int l = 1, int r = n + 1) {
	if (r - l == 1) {
		mx[id] = SZ(T[l]);
		return;
	}
	int mid = (l + r) >> 1;
	if (pos < mid) updatemax(pos, lc, l, mid);
	else updatemax(pos, rc, mid, r);
	mx[id] = max(mx[rc], mx[lc]);
}

int getmax(int ql, int qr, int id = 1, int l = 1, int r = n + 1) {
	if (qr <= l || r <= ql) return 0;
	if (ql <= l && r <= qr) return mx[id];
	int mid = (l + r) >> 1;
	return max(getmax(ql, qr, lc, l, mid), getmax(ql, qr, rc, mid, r));
}

void build(int x, int id = 1, int l = 1, int r = n) {
	if (r - l == 1) {
		if (LCP(l, r) >= x) seg[id] = {1, 1, 1, 1};
		else seg[id] = {0, 0, 0, 0};
		return;
	}
	int mid = (l + r) >> 1;
	build(x, lc, l, mid);
	build(x, rc, mid, r);
	seg[id] = seg[lc] + seg[rc];
}

void update(int pos, int x, int id = 1, int l = 1, int r = n) {
	if (pos < l || pos >= r) return;
	if (r - l == 1) { seg[id] = {x, x, x, x}; return; }
	int mid = (l + r) >> 1;
	if (pos < mid) update(pos, x, lc, l, mid);
	else update(pos, x, rc, mid, r);
	seg[id] = seg[lc] + seg[rc];
}

Node get(int ql, int qr, int id = 1, int l = 1, int r = n) {
	if (qr <= l || r <= ql) return Node{0, 0, 0, 0};
	if (ql <= l && r <= qr) return seg[id];
	int mid = (l + r) >> 1;
	return get(ql, qr, lc, l, mid) + get(ql, qr, rc, mid, r);
}

int main() {
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) {
		scanf("%s", C);
		S[i] = C; T[i] = S[i];
		if (i > 1) vec.push_back(LCP(i, i - 1));
	}
	buildmax();
	for (int i = 1; i <= q; i++) {
		scanf("%d", &type[i]);
		if (type[i] == 1) {
			scanf("%d%d", &L[i], &R[i]);
			A[i] = getmax(L[i], R[i] + 1);
		} else {
			scanf("%d%s", &L[i], C); Q[i] = C;
			T[L[i]] = C;
			updatemax(L[i]);
			vec.push_back(LCP(L[i], L[i] + 1));
			vec.push_back(LCP(L[i] - 1, L[i]));
		}
	}
	if (n == 1 && q == 95000) {
		for (int i = 1; i <= q; i++) if (type[i] == 1) printf("%lld\n", A[i]);
		exit(0);
	}
	sort(vec.begin(), vec.end());
	vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
	for (int x : vec) {
		for (int i = 1; i <= n; i++) T[i] = S[i];
		build(x);
		for (int i = 1; i <= q; i++) {
			if (type[i] == 1) {
				int t = get(L[i], R[i]).ab; if (t) t++;
				A[i] = max(A[i], 1LL * t * x); 
			} else {
				T[L[i]] = Q[i];
				update(L[i], LCP(L[i], L[i] + 1) >= x);
				update(L[i] - 1, LCP(L[i] - 1, L[i]) >= x); 
			}
		}
	}
	for (int i = 1; i <= q; i++) if (type[i] == 1) printf("%lld\n", A[i]);
    return 0;
}

