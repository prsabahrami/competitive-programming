#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
 
#define SZ(x)                       (int) x.size()
#define F                           first
#define S                           second

const int N = 1e5 + 10, MOD = 1e9 + 7;
int P[N], S[N], F[N], B[N], H[N], mn[N], M[N], n, m, timer = 0;
vector<pii> adj[N], L; pii E[N];

void preDFS(int v, int p = -1) {
	mn[v] = H[v]; M[v] = 1;
	for (pii u : adj[v]) {
		if (!M[u.F]) {
			H[u.F] = H[v] + 1; 
			preDFS(u.F, v);
			mn[v] = min(mn[v], mn[u.F]);
			if (mn[u.F] >= H[u.F]) B[u.S] = 1;
		} else if (u.F != p) mn[v] = min(mn[v], H[u.F]);
	}
}

int Find(int v) {
	return !P[v] ? v : P[v] = Find(P[v]);
}	

void Union(int u, int v) {
	u = Find(u), v = Find(v);
	if (u != v) P[u] = v;
	return; 
}

void DFS(int v, int p = -1) {
	S[v] = timer++;
	for (pii u : adj[v]) {
		if (u.F != p) DFS(u.F, v);
	}
}

int main() {
	scanf("%d%d", &n, &m);
	if (n == 2) return !printf("-1\n");
	for (int i = 1; i <= m; i++) {
		int u, v; scanf("%d%d", &u, &v);
		adj[u].push_back({v, i}); E[i] = {u, v};
		adj[v].push_back({u, i});
	}
	preDFS(1);
	for (int i = 1; i <= m; i++) {
		if (!B[i]) Union(E[i].F, E[i].S);
	}
	for (int i = 1; i <= n; i++) adj[i] = {};
	for (int i = 1; i <= m; i++) {
		if (B[i]) {
			int u = Find(E[i].F), v = Find(E[i].S);
			adj[u].push_back({v, i});
			adj[v].push_back({u, i});
		}
	}
	int rt = 1;
	for (int i = 1; i <= n; i++) if (i == Find(i) && SZ(adj[i]) > 1) rt = i;
	DFS(rt);
	for (int i = 1; i <= n; i++) {
		if (i != Find(i)) continue;
		if (SZ(adj[i]) == 1) L.push_back({S[i], i});
	}
	sort(L.begin(), L.end());
	if (!SZ(L)) return !printf("0\n");
	printf("%d\n", (SZ(L) + 1) / 2);
	for (int i = 0; i < (SZ(L) + 1) / 2; i++) {
		printf("%d %d\n", L[i].S, L[i + SZ(L) / 2].S);
	}
    return 0;
}

