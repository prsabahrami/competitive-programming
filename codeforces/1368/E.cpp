#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
 
#define SZ(x)                       (int) x.size()
#define F                           first
#define S                           second

const int N = 2e5 + 10, MOD = 1e9 + 7;
int n, m, q, dead[N], nalive[N], M[N];
vector<int> adj[N], topo;

void DFS(int v) {
	M[v] = 1;
	for (int u : adj[v]) {
		if (!M[u]) DFS(u);
	}
	topo.push_back(v);
}

int main() {
	for (scanf("%d", &q); q; q--) {
		scanf("%d%d", &n, &m); vector<int> vec;
		for (int i = 1; i <= m; i++) {
			int u, v; scanf("%d%d", &u, &v);
			adj[u].push_back(v);
		}
		for (int i = 1; i <= n; i++) {
			if (!M[i]) DFS(i);
		}
		reverse(topo.begin(), topo.end());
		for (int i = 0; i < n; i++) {
			int v = topo[i];
			if (!dead[v]) {
				for (int u : adj[v]) {
					if (nalive[v]) dead[u] = 1;
					else nalive[u] = 1;
				}
			} else vec.push_back(v);
		}
		printf("%d\n", SZ(vec));
		for (int v : vec) printf("%d ", v);
		printf("\n");
		topo = {};
		for (int i = 1; i <= n; i++) adj[i] = {}, M[i] = dead[i] = nalive[i] = 0;
	}
	return 0;
}
