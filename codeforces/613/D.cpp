#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
 
#define SZ(x)                       (int) x.size()
#define F                           first
#define S                           second

const int N = 1e5 + 10, MOD = 1e9 + 7, LOG = 19;
int F[N], M[N], P[LOG][N], H[N], S[N], n, q, tim, f; ll dp[2][N];
vector<int> adj[N]; vector<pii> vec, temp; stack<int> st;

void DFS(int v, int p = -1) {
	S[v] = tim++;
	if (p == -1) P[0][v] = v;
	for (int i = 1; i < LOG; i++) {
		P[i][v] = P[i - 1][P[i - 1][v]];
	}
	for (int u : adj[v]) {
		if (u != p) {
			H[u] = H[v] + 1, P[0][u] = v;
			DFS(u, v);
		}
	}
	F[v] = tim;
}

int getpar(int v, int h) {
	for (int i = LOG; i--;) {
		if (h & (1 << i)) v = P[i][v];
	}
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

void calcDFS(int v) {
	ll s1 = 0, s2 = 0;
	for (int u : adj[v]) {
		calcDFS(u), s1 += dp[0][u], s2 += dp[1][u];
	}
	if (M[v]) {
		dp[0][v] = s2;
		dp[1][v] = 1e6;
	} else {
		dp[0][v] = 1 + s1;
		dp[1][v] = min(1 + s1, s2);
		for (int u : adj[v]) {
			dp[0][v] = min(dp[0][v], s2 - dp[1][u] + dp[0][u]);
		}
	}
	//printf("%d %lld %lld\n", v, dp[0][v], dp[1][v]);
}

void CLEAR(int v) {
	for (int u : adj[v]) {
		if (u != v)
			CLEAR(u);
	}
	adj[v] = {}, M[v] = 0; dp[0][v] = dp[1][v] = 0;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int u, v; scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	DFS(1);
	for (int i = 1; i <= n; i++) adj[i] = {};
	for (scanf("%d", &q); q; q--) {
		int k; scanf("%d", &k); vec = temp = {}; f = 1;
		for (int i = 1; i <= k; i++) {
			int v; scanf("%d", &v); M[v] = 1;
			vec.push_back({S[v], v});
			if (P[0][v] != v && M[P[0][v]]) f = 0;
		}
		sort(vec.begin(), vec.end()); temp = vec;
		for (int i = 0; i < SZ(vec); i++) {
			int p = LCA(vec[i].S, vec[(i + 1) % SZ(vec)].S);
			if (P[0][vec[i].S] != vec[i].S && M[P[0][vec[i].S]]) f = 0;
			temp.push_back({S[p], p});
		}
		sort(temp.begin(), temp.end()); vec = {}; vec.swap(temp);
		vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
		while (SZ(st)) st.pop();
		st.push(vec[0].S);
		for (int i = 1; i < SZ(vec); i++) {
			pii x = vec[i];
			while (F[x.S] > F[st.top()]) st.pop();
			if (M[x.S] && M[st.top()]) {
				adj[st.top()].push_back(P[0][x.S]);
				adj[P[0][x.S]].push_back(x.S);
			}
			else adj[st.top()].push_back(x.S);
			st.push(x.S);
		}
		if (!f) {
			CLEAR(vec[0].S); printf("-1\n");
			continue;
		}
		calcDFS(vec[0].S);
		printf("%lld\n", dp[0][vec[0].S]);
		CLEAR(vec[0].S);
	}
	return 0;
}
