#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
 
#define SZ(x)                       (int) x.size()
#define F                           first
#define S                           second

const int N = 1e6 + 10;
int n, k, M[N], dp[N], P[20][N], C[N], S[N], gc = 0;
vector<int> adj[N], out[N], in[N], topo; vector<pii> E;

void DFS(int v, int p = -1) {
    if (p == -1) P[0][v] = v;
    for  (int i = 1; i < 20; i++) {
        P[i][v] = P[i - 1][P[i - 1][v]];
    }
    for (int u : adj[v]) {
        DFS(u, v);
    }
}

void topoDFS(int v) {
    M[v] = 1;
    for (int u : out[v]) {
        if (!M[u]) topoDFS(u);
    }
    topo.push_back(v);
}

void add_edge(int u, int v) {
    out[u].push_back(v);
    in[v].push_back(u);
    E.push_back({u, v});
}

void sccDFS(int v) {
    C[v] = gc;
    M[v] = 1;
    for (int u : in[v]) {
        if (!M[u]) sccDFS(u);
    }
}

int getpar(int v, int h) {
    for (int i = h; i; i -= i & -i) {
        v = P[__builtin_ctz(i)][v];
    }
    return v;
}

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 2; i <= n; i++) {
        int p; scanf("%d", &p);
        P[0][i] = p;
        add_edge(p, i);
        adj[p].push_back(i);
    }    
    DFS(1);
    for (int i = 1; i <= n; i++) {
        if (!SZ(adj[i])) add_edge(i, getpar(i, k));
    }
    for (int i = 1; i <= n; i++) {
        if (!M[i]) topoDFS(i);
    }
    reverse(topo.begin(), topo.end());
    memset(M, 0, sizeof M);
    for (int v : topo) {
        if (!M[v]) {
            sccDFS(v), gc++;
        }
    }
    for (int i = 1; i <= n; i++) in[i] = out[i] = {};
    for (int i = 1; i <= n; i++) {
        if (!SZ(adj[i])) S[C[i]]++;
    }
    for (pii x : E) {
        if (C[x.F] != C[x.S]) {
            out[C[x.F]].push_back(C[x.S]);
            in[C[x.S]].push_back(C[x.F]);
        }
    }
    memset(M, 0, sizeof M); topo = {};
    for (int i = 0; i < gc; i++) {
        if (!M[i]) topoDFS(i);
    }
    for (int v : topo) {
        for (int u : out[v]) {
            dp[v] = max(dp[v], dp[u]);
        }
        dp[v] += S[v];
    }
    printf("%d\n", dp[C[1]]);
    return 0;
}


















