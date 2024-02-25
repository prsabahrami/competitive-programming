#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
 
#define SZ(x)                       (int) x.size()
#define F                           first
#define S                           second

const int N = 1e5 + 10, MOD = 1e9 + 7, LOG = 19;
vector<int> adj[N]; set<pii> weed, lsd;
int val[N], S[N], R[N], P[LOG][N], H[N], n, A, timer;

void preDFS(int v, int p = -1) {
	if (p == -1) P[0][v] = v; 
	S[v] = timer++;
	for (int i = 1; i < LOG; i++) {
		P[i][v] = P[i - 1][P[i - 1][v]];
	}
	for (int u : adj[v]) {
		if (u != p) {
			H[u] = H[v] + 1, P[0][u] = v;
			preDFS(u, v);
		}
	}
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
		if (P[i][u] != P[i][v]) {
			v = P[i][v], u = P[i][u];
		}
	}
	return P[0][v];
}

int dist(int u, int v) {
	return H[u] + H[v] - 2 * H[LCA(u, v)];
}

void add(int v) {
	auto it = weed.lower_bound({S[v], v});
	auto it2 = it;
	it++;
	if (it == weed.end()) it = weed.begin();
	if (it2 == weed.begin()) it2 = weed.end();
	it2--;
	int prv = it2->S, nxt = it->S;
	lsd.erase({val[v], v});
	val[v] = dist(v, prv) + dist(nxt, v) - dist(nxt, prv);
	lsd.insert({val[v], v});
}


int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int u, v; scanf("%d%d", &u, &v);
		adj[v].push_back(u);
		adj[u].push_back(v);
	}
	preDFS(1);
	for (int i = 1; i <= n; i++) {
		if (SZ(adj[i]) == 1) {
			weed.insert({S[i], i});
		}
	}
	for (int i = 1; i <= n; i++) {
		if (SZ(adj[i]) == 1) {
			add(i);
		}
	}
	A = 2 * n - 2;
	for (int i = SZ(weed); i <= n; i++) {
		R[i] = A / 2 + 1;
	}
	for (int i = SZ(weed) - 1; i >= 1; i--) {
		int v = lsd.begin()->S; A -= lsd.begin()->F;
		lsd.erase(lsd.begin());
		auto it = weed.lower_bound({S[v], v});
		auto it2 = it;
		it++;
		if (it == weed.end()) it = weed.begin();
		if (it2 == weed.begin()) it2 = weed.end();
		it2--;
		int prv = it2->S, nxt = it->S;
		weed.erase({S[v], v});
		add(prv); add(nxt);
		R[i] = A / 2 + 1;
	}
	for (int i = 1; i <= n; i++) printf("%d ", R[i]);
	printf("\n");
    return 0;
}

