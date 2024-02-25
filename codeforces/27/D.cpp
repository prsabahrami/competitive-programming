#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;
 
#define SZ(x)                       (ll) x.size()
#define F                           first
#define S                           second

const ll N = 200 + 10;
pair<int, int> E[N];
vector<int> out[N], in[N], topo;
int C[N], M[N], n, m, gc;

int check(int u1, int v1, int u2, int v2) {
	return (u2 > u1 && u2 < v1 && v2 > v1) || (v2 > u1 && v2 < v1 && u2 < u1);
}

void add_edge(int u, int v) {
	out[u].push_back(v);
	in[v].push_back(u);
}

void preDFS(int v) {
	M[v] = 1;
	for (int u : out[v]) {
		if (M[u] == 0) preDFS(u);
	}
	topo.push_back(v);
}
 
void DFS(int v) {
	M[v] = 1;
	C[v] = gc;
	for (int u : in[v]) {
		if (M[u] == 0) DFS(u);
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &E[i].F, &E[i].S);
		if (E[i].F > E[i].S) swap(E[i].F, E[i].S);
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j < i; j++) {
			if (!check(E[i].F, E[i].S, E[j].F, E[j].S)) continue;
			int u = i + i, v = j + j;
			add_edge(u ^ 1, v);
            add_edge(u, v ^ 1);
            add_edge(v ^ 1, u);
            add_edge(v, u ^ 1);
		}
	}
	for (int i = 1; i < 2 * (m + 1); i++) {
		if (!M[i]) preDFS(i);
	}
	fill(M, M + N, 0);
	reverse(topo.begin(), topo.end());
	for (int v : topo) if (!M[v]) DFS(v), gc++;
	for (int i = 1; i <= m; i++) {
		int v = i + i;
		if (C[v] == C[v ^ 1]) return !printf("Impossible");
	}
	for (int i = 1; i <= m; i++) {
		if (C[2 * i] > C[2 * i + 1]) printf("i");
		else printf("o");
	}
    return 0;
}

