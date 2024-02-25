/* I do it for the glory */
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
 
#define SZ(x)                       (int) x.size()
#define F                           first
#define S                           second
#define lc                          id << 1
#define rc                          lc | 1

const int N = 5e5 + 10, MOD = 1e9 + 7;
int seg[N << 2], lz[N << 2], pos[N], up[N], F[N], M[N], H[N], S[N], n, k; vector<int> adj[N], vec[N];

void bld(int id = 1, int l = 1, int r = k + 1) {
    if (r - l < 2) { seg[id] = -k + l - 1; return; }
    int md = (l + r) >> 1;
    bld(lc, l, md), bld(rc, md, r);
    seg[id] = min(seg[lc], seg[rc]);
}

void DFS(int v, int c = 1, int p = -1, int m = 0, int f = MOD) {
    up[v] = H[m];
    if (H[v] < H[m]) c = 1, m = v, f = MOD;
    else if (H[v] == H[m]) c++, f = MOD;
    else f = min(f, H[v]);
    F[v] = f; M[v] = H[m];
    if (c < 2) vec[m].push_back(v);
    for (int &u : adj[v]) 
        if (u != p) DFS(u, c, v, m, f);
}

inline void shft(int id, int l, int r) {
    seg[id] += lz[id];
    if (r - l > 1) { lz[lc] += lz[id], lz[rc] += lz[id]; }
    lz[id] = 0;
}

void upd(int ql, int qr, int x, int id = 1, int l = 1, int r = k + 1) {
    if (lz[id]) shft(id, l, r);
    if (qr <= l || r <= ql || ql >= qr) return;
    if (ql <= l && r <= qr) { lz[id] += x; return shft(id, l, r); }
    int md = (l + r) >> 1;
    upd(ql, qr, x, lc, l, md), upd(ql, qr, x, rc, md, r);
    seg[id] = min(seg[lc], seg[rc]);
}

int check(int &v, int x) {
    for (int &u : vec[v]) {
        int p = lower_bound(S + 1, S + k + 1, min({x, up[v], F[u]}) + 1) - S - 1;
        upd(pos[u] + 1, p + 1, 1);
    }
    int f = (seg[1] >= 0);
    for (int &u : vec[v]) {
        int p = lower_bound(S + 1, S + k + 1, min({x, up[v], F[u]}) + 1) - S - 1;
        upd(pos[u] + 1, p + 1, -1);
    }
    return f;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &H[i]);
    for (int i = 1; i < n; i++) {
        int u, v; scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    } H[0] = MOD;
    DFS(1);
    scanf("%d", &k);
    for (int i = 1; i <= k; i++) 
        scanf("%d", &S[i]);
    sort(S + 1, S + k + 1);
    bld();
    for (int i = 1; i <= n; i++) {
        pos[i] = lower_bound(S + 1, S + k + 1, M[i] + 1) - S - 1;
        upd(1, pos[i] + 1, 1);
    }
    if (seg[1] >= 0) return !printf("0\n");
    int ret = MOD;
    for (int i = 1; i <= n; i++) {
        int l = pos[i] - 1, r = k + 1;
        if (!check(i, ret + H[i])) continue;
        while (r - l > 1) {
            int md = (l + r) >> 1;
            if (check(i, S[md])) r = md, ret = min(ret, S[md] - H[i]);
            else l = md;
        }
    }
    printf("%d\n", ret >= MOD ? -1 : ret);
    return 0;
}

