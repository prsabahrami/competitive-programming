#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
 
#define SZ(x)                       (int) x.size()
#define F                           first
#define S                           second

const int N = 3e5 + 10, MOD = 1e9 + 7;
int seg[N << 2], A[N], M[N], n, q;

void build(int id = 1, int l = 1, int r = n + 1) {
	if (r - l == 1) {
		seg[id] = A[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(id << 1, l, mid);
	build(id << 1 | 1, mid, r);
	seg[id] = min(seg[id << 1], seg[id << 1 | 1]);
}

int get(int ql, int qr, int id = 1, int l = 1, int r = n + 1) {
	if (qr <= l || r <= ql) return MOD;
	if (ql <= l && r <= qr) return seg[id];
	int mid = (l + r) >> 1;
	return min(get(ql, qr, id << 1, l, mid), get(ql, qr, id << 1 | 1, mid, r));
}

int check(int x) {
	fill(M, M + n + 1, 0);
	for (int i = 1; i <= n - x + 1; i++) {
		int k = get(i, i + x);
		if (M[k]) return 0;
		M[k] = 1;
	}
	for (int i = 1; i <= n - x + 1; i++) {
		if (!M[i]) return 0;
	}
	return 1;
}

int main() {
	scanf("%d", &q);
	while (q--) {
		scanf("%d", &n); int f = 0;
		for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
		build();
		for (int i = 1; i <= n; i++) {
			if (M[A[i]]) f = 1;
			M[A[i]] = 1;
		}
		int l = 1, r = n + 1;
		while (r - l > 1) {
			int mid = (l + r) >> 1;
			if (check(mid)) r = mid;
			else l = mid;
		}
		if (f) printf("0");
		else printf("1");
		for (int i = 2; i <= n; i++) {
			if (i < r) printf("0");
			else printf("1");
		}
		printf("\n");
		fill(M, M + n + 1, 0);
	}
	return 0;
}
