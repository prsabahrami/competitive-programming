/* Just a drop of water in an endless sea */
#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
 
#define SZ(x) (int) x.size()
#define F first
#define S second

const int N = 1e6 + 10, MOD = 1e9 + 7;
int C[N], P[19][N], H[N], C2[N], CP[N], n, m, fk;
vector<int> adj[N]; vector<pii> vec[N]; ll ret;

void preDFS(int v, int p = -1) {
    if (!~p) P[0][v] = v;
    for (int i = 1; i < 19; i++) 
        P[i][v] = P[i - 1][P[i - 1][v]];
    for (int &u : adj[v]) {
        if (u != p) 
            H[u] = H[v] + 1, P[0][u] = v, preDFS(u, v);
    }
}

int getpar(int v, int h) {
    for (; h; h -= h & -h) 
        v = P[__builtin_ctz(h)][v];
    return v;
}

int LCA(int u, int v) {
    if (H[u] < H[v]) swap(u, v);
    u = getpar(u, H[u] - H[v]);
    for (int i = 18; ~i; i--) 
        if (P[i][u] != P[i][v]) 
            v = P[i][v], u = P[i][u];
    return u ^ v ? P[0][v] : v;
}

void cDFS(int v, int p = -1) {
    for (int &u : adj[v]) 
        if (u != p) cDFS(u, v), C[v] += C[u], C2[v] += C2[u];
}

void DFS(int v, int p = -1) {
    int pt = -1;
    for (int i = 0; i < SZ(vec[v]); i++) {
        for (; pt + 1 < i && vec[v][pt + 1].F != vec[v][i].F; pt++, CP[vec[v][pt].S]++);
        ret += pt + 1 - CP[vec[v][i].S] - CP[vec[v][i].F];
    }
    for (; ~pt; pt--) CP[vec[v][pt].S]--;
    for (pii &pth : vec[v]) {
        ret += C[v] - C2[pth.F] - C2[pth.S];
    }
    for (int &u : adj[v]) 
        if (u != p) DFS(u, v);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int u, v; scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    preDFS(1);
    scanf("%d", &m);
    fk = n;
    for (int i = 1; i <= m; i++) {
        int u, v; scanf("%d%d", &u, &v);
        if (H[u] < H[v]) swap(u, v);
        int p = LCA(u, v); C[u]++, C[v]++, C[p] -= 2;
        if (v ^ p) C2[v]++, C2[getpar(v, H[v] - H[p] - 1)]--;
        if (u ^ p) C2[u]++, C2[getpar(u, H[u] - H[p] - 1)]--;
        if (getpar(u, H[u] - H[v]) ^ v) {
            int cu = getpar(u, H[u] - H[p] - 1), cv = getpar(v, H[v] - H[p] - 1);
            if (cu < cv) swap(cv, cu);
            vec[p].push_back({cv, cu});
        } else {
           if (u ^ v) vec[p].push_back({getpar(u, H[u] - H[v] - 1), ++fk});
           else {
               int x = ++fk, y = ++fk;
               vec[p].push_back({x, y});
           }
        }
    }
    cDFS(1);
    for (int i = 1; i <= n; i++) 
        sort(begin(vec[i]), end(vec[i]));
    DFS(1);
    printf("%lld\n", ret);
    return 0;
}

