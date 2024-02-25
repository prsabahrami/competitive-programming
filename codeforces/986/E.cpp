/* I do it for the glory */
#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
 
#define SZ(x) (int) x.size()
#define F first
#define S second

int Pow(int a, int b, int md, int ret = 1) {
    for (; b; b >>= 1, a = 1ll * a * a % md) 
        if (b & 1) ret = 1ll * ret * a % md;
    return ret;
}

const int N = 1e5 + 10, MOD = 1e9 + 7, M = 1e7 + 5;
int bp[M], ret[N], C[N * 8][25], P[18][N], H[N], A[N], n, q;
vector<int> adj[N], prs; vector<array<int, 4>> vec[N];

void preDFS(int v, int p = -1) {
    if (!~p) P[0][v] = 1;
    for (int i = 1; i < 18; i++) 
        P[i][v] = P[i - 1][P[i - 1][v]];
    for (int &u : adj[v]) {
        if (u != p) H[u] = H[v] + 1, P[0][u] = v, preDFS(u, v);
    }
}

int get(int x) {
    return lower_bound(begin(prs), end(prs), x) - begin(prs);
}

int LCA(int u, int v) {
    if (H[u] < H[v]) swap(u, v);
    for (int i = H[u] - H[v]; i; i -= i & -i)
        u = P[__builtin_ctz(i)][u];
    for (int i = 17; ~i; i--) {
        if (P[i][v] != P[i][u]) 
            u = P[i][u], v = P[i][v];
    }
    return u ^ v ? P[0][v] : v;
}

inline void addQ(int p, int u, int v, int x, int id, int tw) {
    vec[u].push_back({id, 1, x, tw});
    vec[v].push_back({id, 1, x, tw});
    vec[p].push_back({id, -1, x, tw});
    if (p > 1) vec[P[0][p]].push_back({id, -1, x, tw});
}

void DFS(int v, int p = -1) {
    for (int x = A[v]; x > 1; x /= bp[x]) {
        int c = 1;
        for (; bp[x] == bp[x / bp[x]]; x /= bp[x]) c++;
        C[get(bp[x])][c]++;
    }
    for (auto i : vec[v]) {
        int id = i[0], s = i[1], pr = i[2], tw = i[3], x = 0;
        for (int j = 1; j < 25; j++) 
                x += min(tw, j) * C[get(pr)][j];
        if (~s) ret[id] = 1ll * ret[id] * Pow(pr, x, MOD) % MOD;
        else ret[id] = 1ll * ret[id] * Pow(Pow(pr, x, MOD), MOD - 2, MOD) % MOD;
    }
    for (int &u : adj[v]) 
        if (u != p) DFS(u, v);
    for (int x = A[v]; x > 1; x /= bp[x]) {
        int c = 1;
        for (; bp[x] == bp[x / bp[x]]; x /= bp[x]) c++;
        C[get(bp[x])][c]--;
    }
}

int main() {
    for (int i = 2; i < M; i++) {
        if (!bp[i]) 
            for (int j = i; j < M; j += i) bp[j] = i;
    }
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int u, v; scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    preDFS(1);
    scanf("%d", &q);
    for (int i = 1; i <= n; i++) 
        for (int x = A[i]; x > 1; x /= bp[x]) 
            if (bp[x] ^ bp[x / bp[x]]) prs.push_back(bp[x]);
    for (int i = 1; i <= q; i++) {
        ret[i] = 1;
        int u, v, x; scanf("%d%d%d", &u, &v, &x); int p = LCA(u, v);
        for (; x > 1; x /= bp[x]) {
            int c = 1;
            for (; bp[x] == bp[x / bp[x]]; x /= bp[x]) c++;
            prs.push_back(bp[x]);
            addQ(p, u, v, bp[x], i, c);
        }
    }
    sort(begin(prs), end(prs));
    prs.resize(unique(begin(prs), end(prs)) - begin(prs));
    assert(SZ(prs) < 8 * N);
    DFS(1);
    for (int i = 1; i <= q; i++) printf("%d\n", ret[i]);
    return 0;
}

