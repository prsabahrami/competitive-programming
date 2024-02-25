#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
 
#define SZ(x)                       (int) x.size()
#define F                           first
#define S                           second

const int N = 1e6 + 10, MOD = 1e9 + 7, LOG = 22;
int P[LOG][N], H[N], D[2], n = 4, q;

void upd(int v, int u) {
	P[0][u] = v; H[u] = H[v] + 1;
	for (int i = 1; i < LOG; i++) P[i][u] = P[i - 1][P[i - 1][u]];
}

int getpar(int v, int h) {
	for (int i = LOG - 1; i--;) if (h & (1 << i)) v = P[i][v];
	return v;
}

int LCA(int u, int v) {
	if (H[u] < H[v]) swap(u, v);
	u = getpar(u, H[u] - H[v]);
	if (u == v) return v;
	for (int i = LOG - 1; i--;) {
		if (P[i][v] != P[i][u]) {
			u = P[i][u], v = P[i][v];
		}
	}
	return P[0][v];
}

int dist(int u, int v) {
	return H[u] + H[v] - 2 * H[LCA(u, v)];
}

void modify(int v, int t) {
	int d = dist(D[0], D[1]), d1 = dist(D[t], v);
	if (d1 > d) D[t ^ 1] = v;
}

int main() {
	scanf("%d", &q);
	P[0][1] = 1; D[0] = 2, D[1] = 3;
	upd(1, 2), upd(1, 3), upd(1, 4);
	while (q--) {
		int v; scanf("%d", &v);
		upd(v, ++n), upd(v, ++n);
		modify(n - 1, 0), modify(n - 1, 1);
		modify(n, 0), modify(n, 1);
		printf("%d\n", dist(D[0], D[1]));
	}
	return 0;
}
