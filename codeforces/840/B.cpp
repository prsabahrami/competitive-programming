#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
 
#define SZ(x)                       (int) x.size()
#define F                           first
#define S                           second

const int N = 3e5 + 10, LOG = 21;
int in[N], D[N], M[N], P[LOG][N], ps[N], H[N], n, m;
vector<pii> adj[N]; pii E[N];

void preDFS(int v) {
    M[v] = 1;
    for (pii u : adj[v]) {
        if (!M[u.F]) {
            in[u.S] = 1;
            P[0][u.F] = v, H[u.F] = H[v] + 1;
            preDFS(u.F);
        }
    }
}

int getpar(int v, int h) {
    for (int i = h; i; i -= i & -i) {
        v = P[__builtin_ctz(i)][v];
    }
    return v;
}

int LCA(int u, int v) {
    if (H[u] < H[v]) swap(u, v);
    u = getpar(u, H[u] - H[v]);
    if (u == v) return v;
    for (int i = LOG; i--;) {
        if (P[i][v] != P[i][u]) {
            u = P[i][u], v = P[i][v];
        }
    }
    return P[0][v];
}

void DFS(int v) {
    M[v] = 1;
    for (pii u : adj[v]) {
        if  (!M[u.F]) {
            DFS(u.F);
            ps[v] += ps[u.F];
        }
    }
}

int main() {
    scanf("%d%d", &n, &m); vector<int> odd;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &D[i]);
        if (D[i] == 1) odd.push_back(i);
    }
    for (int i = 1; i <= m; i++) {
        int u, v; scanf("%d%d", &u, &v);
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
        E[i] = {u, v};
    }
    preDFS(1);
    for (int i = 1; i <= n; i++) {
        if (D[i] == -1 && (SZ(odd) & 1)) odd.push_back(i);
    }
    memset(M, 0, sizeof M);
    if (SZ(odd) & 1) return !printf("-1\n");
    for (int i = 0; i < SZ(odd); i += 2) {
        int p = LCA(odd[i], odd[i + 1]);
        ps[odd[i + 1]]++, ps[odd[i]]++, ps[p] -= 2;
    }
    DFS(1); vector<int> ans;
    for (int i = 1; i <= m; i++) {
        int u = E[i].F, v = E[i].S;
        if (H[u] < H[v]) swap(u, v);
        if (in[i] && (ps[u] & 1)) ans.push_back(i);
    }
    printf("%d\n", SZ(ans));
    for (int x : ans) printf("%d ", x);
    printf("\n");
    return 0;
}
