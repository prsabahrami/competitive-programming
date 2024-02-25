// .[ Nude - Radiohead ].
#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
 
#define SZ(x)                       (int) x.size()
#define F                           first
#define S                           second
#define lc                          id << 1
#define rc                          lc | 1

const int N = 2e5 + 10, MOD = 1e9 + 7;
int seg[N << 2], hd[N], w[N], hv[N], low[N], P[N], H[N], S[N], St[N], n, m, q, ts;
vector<int> adj[N], B, g[N]; multiset<int> st[N];

void add_edge(int u, int v) {
    g[u].push_back(v);
    g[v].push_back(u);
}

void BC_Tree(int v, int p = -1) {
    low[v] = H[v]; B.push_back(v);
    for (int &u : adj[v]) {
        if (H[u]) 
            low[v] = min(low[v], H[u]);
        else H[u] = H[v] + 1, BC_Tree(u, v), low[v] = min(low[v], low[u]);
    }
    if ((low[v] + 1) ^ H[v]) return;
    int u = 0;
    while (u ^ v) { u = B.back(); add_edge(v + n, u); B.pop_back(); }
    if (~p) add_edge(v + n, p);
}

void DFS(int v, int p = -1) {
    S[v] = 1;
    for (int u : g[v]) 
        if (u != p) DFS(u, v), S[v] += S[u];
    for (int &u : g[v])     
        if (u != p && S[u] > S[hv[v]]) hv[v] = u;
}

void hldDFS(int v, int p = -1) {
    St[v] = ts++; P[v] = p;
    if (!~p) hd[v] = v;
    if (hv[v]) H[hv[v]] = H[v] + 1, hd[hv[v]] = hd[v], hldDFS(hv[v], v);
    for (int &u : g[v]) 
        if (u != p && u != hv[v]) H[u] = H[v] + 1, hd[u] = u, hldDFS(u, v);
}

void _upd(int p, int x, int id = 1, int l = 0, int r = ts) {
    if (r - l < 2) { seg[id] = x; return; }
    int md = (l + r) >> 1;
    p < md ? _upd(p, x, lc, l, md) : _upd(p, x, rc, md, r);
    seg[id] = min(seg[lc], seg[rc]);
}

void upd(int v, int prv, int nw) {
    if (!~v) return;
    auto it = st[v].find(prv);
    if (it != st[v].end()) st[v].erase(it);
    st[v].insert(nw);
    _upd(St[v], *st[v].begin());
}

int get(int ql, int qr, int id = 1, int l = 0, int r = ts) {
    if (qr <= l || r <= ql) return MOD;
    if (ql <= l && r <= qr) return seg[id];
    int md = (l + r) >> 1;
    return min(get(ql, qr, lc, l, md), get(ql, qr, rc, md, r));
}

int query(int u, int v) {
    int tu = u, tv = v, p = u, ret = MOD;
    for (; hd[v] != hd[u]; ) {
        if (H[hd[v]] < H[hd[u]]) u = P[hd[u]];
        else v = P[hd[v]];
    }
    p = (H[v] > H[u] ? u : v);
    u = tu, v = tv;
    for (; hd[v] != hd[p]; v = P[hd[v]]) 
        ret = min(ret, get(St[hd[v]], St[v] + 1));
    ret = min(ret, get(St[p], St[v] + 1));
    for (; hd[u] != hd[p]; u = P[hd[u]]) 
        ret = min(ret, get(St[hd[u]], St[u] + 1));
    ret = min(ret, get(St[p], St[u] + 1));
    if (p > n) ret = min(ret, w[P[p]]);
    return ret;
}

int main() {
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= n; i++) 
        scanf("%d", &w[i]);
    for (int i = 1; i <= m; i++) {
        int u, v; scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    H[1] = 1, BC_Tree(1); 
    DFS(1);
    H[1] = 0, hldDFS(1);
    for (int i = 1; i <= n; i++) {
        _upd(St[i], w[i]);
        upd(P[i], -1, w[i]);
    }
    for (; q; q--) {
        char T[2]; int v, u; scanf("%s%d%d", T, &v, &u);
        if (T[0] != 'A') {
            upd(P[v], w[v], u);
            w[v] = u, _upd(St[v], u);
        } else printf("%d\n", query(u, v));
    }
    return 0;
}

