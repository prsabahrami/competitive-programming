#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
 
#define SZ(x)                       (int) x.size()
#define F                           first
#define S                           second
#define lc                          id << 1
#define rc                          lc | 1

const int N = 2e5 + 10, LOG = 21;
struct Nude {
    int pl, pr, f;
};
int HD[N], S[N], M[N], St[N], Ft[N], D[N], P[N], A[N], H[N], n, q, tim; vector<int> adj[N];
Nude seg[N << 2], gn;

void preDFS(int v) { 
    S[v] = 1;
    for (int u : adj[v]) {
        H[u] = H[v] + 1;
        preDFS(u);
        S[v] += S[u];
        if (S[u] > S[M[v]]) M[v] = u;
    }
}

void HLD(int v) {
    if (v == 1) HD[v] = v;
    if (M[v]) HD[M[v]] = HD[v], HLD(M[v]);
    for (int u : adj[v]) {
        if (u != M[v]) HD[u] = u, HLD(u);
    }
}

int LCA(int u, int v) {
    while (HD[u] != HD[v]) {
        if (H[HD[v]] < H[HD[u]]) u = P[HD[u]];
        else v = P[HD[v]];
    }   
    return H[u] < H[v] ? u : v;
}

int dist(int u, int v) {
    return H[u] + H[v] - 2 * H[LCA(u, v)];
}

int check(int u, int v, int w) {
    return dist(u, w) + dist(v, w) == dist(u, v);
}

Nude operator+(Nude x, Nude y) {
    if (x.f == -1) return y;
    if (y.f == -1) return x;
    Nude z = {-1, -1, x.f || y.f};
    if (z.f) return z;
    int p[] = {x.pl, y.pl, x.pr, y.pr};
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            int msk = 15 - (1 << j) - (1 << i); 
            assert(__builtin_popcount(msk) == 2);
            int u = __builtin_ctz(msk), v = 31 - __builtin_clz(msk);
            if (check(p[i], p[j], p[u]) && check(p[i], p[j], p[v])) z.pl = p[i], z.pr = p[j];
        }
    }
    if (z.pl == -1) z.f = 1;
    return z;
}

void build(int id = 1, int l = 0, int r = n) {
    if (r - l == 1) {
        seg[id] = {D[l], D[l], 0};
        //printf("%d %d %d %d %d\n", l, r, seg[id].pl, seg[id].pr, seg[id].f);
        return;
    }
    int mid = (l + r) >> 1;
    build(lc, l, mid);
    build(rc, mid, r);
    seg[id] = seg[lc] + seg[rc];
   // printf("%d %d %d %d %d\n", l, r, seg[id].pl, seg[id].pr, seg[id].f);
}

void update(int pos, int id = 1, int l = 0, int r = n) {
    if (r - l == 1) {
        seg[id] = {D[l], D[l], 0};
        return;
    }
    int mid = (l + r) >> 1;
    if (pos < mid) update(pos, lc, l, mid);
    else update(pos, rc, mid, r);
    seg[id] = seg[lc] + seg[rc];
}

int get(int id = 1, int l = 0, int r = n) {
    Nude t = gn + seg[id];
    if (!t.f) {
        gn = t;
        return -1;
    }
    if (r - l == 1) return l;
    int mid = (l + r) >> 1;
    //printf("%d %d %d %d %d\n", l, r, gn.pl, gn.pr, gn.f);
    int res = get(lc, l, mid);
    if (~res) return res;
    return get(rc, mid, r);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
        D[A[i]] = i;
    }
    P[1] = 1;
    for (int i = 2; i <= n; i++) {
        int p; scanf("%d", &p);
        adj[p].push_back(i);
        P[i] = p;
    }
    preDFS(1);
    HLD(1);
    build();
    for (scanf("%d", &q); q; q--) {
        int t; scanf("%d", &t);
        if (t == 2) {
            gn = {-1, -1, -1};
            int x = get();
            printf("%d\n", (~x ? x : n));
        } else {
            int x, y; scanf("%d%d", &x, &y);
            swap(D[A[x]], D[A[y]]);
            swap(A[x], A[y]);
            update(A[x]), update(A[y]);
        }
    }
    return 0;
}
