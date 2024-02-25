/// The Show Must Go on.........
#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
 
#define SZ(x)                       (int) x.size()
#define F                           first
#define S                           second

const ll N = 3e5 + 10;
vector<pii> adj[N]; vector<int> out[N], in[N], P[N], topo, history;
int gc, timer, n, m, M[N], C[N], W[N];

void add_edge(int u, int v) {
	out[u].push_back(v);
	in[v].push_back(u);
}

void XOR(int u, int v) {
	add_edge(u, v ^ 1);
	add_edge(u ^ 1, v);
	add_edge(v ^ 1, u);
	add_edge(v, u ^ 1);
}

void preDFS(int v) {
	M[v] = 1;
	for (int u : out[v]) if (!M[u]) preDFS(u);
	topo.push_back(v);
}

void sccDFS(int v) {
	M[v] = 1, C[v] = gc;
	for (int u : in[v]) if (!M[u]) sccDFS(u);
}

int check(int x) {
	fill(C, C + N, 0); topo = {};
	fill(M, M + N, 0); gc = 1;
	while (SZ(history)) {
		in[history.back() * 2 + 1].pop_back(), out[history.back() * 2].pop_back();
		history.pop_back();
	}
	for (int i = 1; i <= n; i++) {
		for (pii &u : adj[i]) {
			if (W[u.S] > x) add_edge(u.S * 2, u.S * 2 + 1), history.push_back(u.S);
		}
	}
	for (int i = 0; i < N; i++) {
		if (!M[i]) preDFS(i);
	}
	reverse(topo.begin(), topo.end());
	fill(M, M + N, 0);
	for (int v : topo) if (!M[v]) sccDFS(v), gc++;
	for (int i = 1; i <= timer; i++) {
		if (C[i * 2] == C[i * 2 + 1] && C[i * 2]) return 0;
	}
	return 1;
}

int main() {
	scanf("%d%d", &n, &m); timer = m + 1;
	for (int i = 1; i <= m; i++) {
		int u, v, c; scanf("%d%d%d%d", &u, &v, &c, &W[i]);
		adj[u].push_back({c, i}); P[v].push_back(timer++);
		adj[v].push_back({c, i}); P[u].push_back(timer++);
	}
	for (int v = 1; v <= n; v++) {
		int cnt = 0; unordered_map<int, int> lst;
		for (int j = 0; j < SZ(adj[v]); j++) {
			pii u = adj[v][j]; int &pv = P[v][j];
			if (lst.count(u.F)) {
				cnt++; XOR(u.S * 2, lst[u.F] * 2);
			}
			lst[u.F] = u.S;
			add_edge(pv * 2 + 1, u.S * 2 + 1); add_edge(u.S * 2, pv * 2);
			if (j) add_edge(pv * 2 + 1, P[v][j - 1] * 2 + 1), add_edge(P[v][j - 1] * 2, pv * 2);
			if (j) add_edge(u.S * 2, P[v][j - 1] * 2 + 1), add_edge(P[v][j - 1] * 2, u.S * 2 + 1);
		}
		if (cnt > 1) return !printf("No\n");
	}
	int l = -1, r = 1e9 + 7;
	while (r - l > 1) {
		int mid = (l + r) >> 1;
		if (check(mid)) r = mid;
		else l = mid;
	}
	if (!check(r)) return !printf("No\n");
	printf("Yes\n%d ", r);
	vector<int> A;
	for (int i = 1; i <= m; i++) {
		if (C[2 * i] > C[2 * i + 1]) A.push_back(i);
	}
	printf("%d\n", SZ(A));
	for (int x : A) printf("%d ", x);
	printf("\n");
    return 0;
}

