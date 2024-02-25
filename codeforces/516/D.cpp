/*
When you cried, I'd wipe away all of your tears
When you'd scream, I'd fight away all of your fears
And I held your hand through all of these years
But you still have all of me
*/
#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
 
#define SZ(x)                       (int) x.size()
#define F                           first
#define S                           second
#define lc                          id << 1
#define rc                          lc | 1

const int N = 1e5 + 10;
int tim, n, q, E[N], P[N], St[N], Ft[N]; ll dp[2][N], R[N], L;
vector<pii> adj[N], vec; vector<ll> seg[N << 2];

void merge(ll x, int v, pair<pair<ll, int>, pair<ll, int>> &mx) {
   if (x > mx.S.F) mx.S = {x, v};
   if (mx.F < mx.S) swap(mx.F, mx.S);
}

void downDFS(int v, int p = -1) {
    for (pii u : adj[v]) {
        if (u.F != p) {
            downDFS(u.F, v);
            dp[0][v] = max(dp[0][v], dp[0][u.F] + u.S);
        }
    }
}

void upDFS(int v, int p = -1) {
    pair<pair<ll, int>, pair<ll, int>> mx = {{-1e18, -1}, {-1e18, -1}};
    merge(dp[1][v], v, mx);
    for (pii u : adj[v]) if (u.F != p) merge(dp[0][u.F] + u.S, u.F, mx);
    for (pii u : adj[v]) {
        if (u.F != p) {
            if (u.F == mx.F.S) dp[1][u.F] = mx.S.F;
            else dp[1][u.F] = mx.F.F;
            dp[1][u.F] += u.S;
        }
    }
    for (pii u : adj[v]) if (u.F != p) upDFS(u.F, v);
}

void build(int id = 1, int l = 0, int r = tim) {
    if (r - l == 1) {
        seg[id].push_back(R[E[l]]);
        return;
    }
    int mid = (l + r) >> 1;
    build(lc, l, mid);
    build(rc, mid, r);
    merge(seg[lc].begin(), seg[lc].end(), seg[rc].begin(), seg[rc].end(), back_inserter(seg[id]));
}

int get(int ql, int qr, ll x, int id = 1, int l = 0, int r = tim) {
    if (qr <= l || r <= ql) return 0;
    if (ql <= l && r <= qr) return upper_bound(seg[id].begin(), seg[id].end(), x) - seg[id].begin();
    int mid = (l + r) >> 1;
    return get(ql, qr, x, lc, l, mid) + get(ql, qr, x, rc, mid, r);
}

void DFS(int v, int p = -1) {
    St[v] = tim++; E[St[v]] = v;
    for (pii u : adj[v]) {
        if (u.F != p) DFS(u.F, v);
    }
    Ft[v] = tim;
}

void solve() {
    scanf("%lld", &L);
    int A = 0;
    for (int i = 1; i <= n; i++) {
        A = max(A, get(St[i], Ft[i], R[i] + L));
    }
    printf("%d\n", A);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int u, v, w; scanf("%d%d%d", &u, &v, &w);
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    downDFS(1);
    upDFS(1);
    for (int i = 1; i <= n; i++) {
        R[i] = max(dp[0][i], dp[1][i]);
        P[i] = i;
    }
    sort(P + 1, P + n + 1, [&] (int x, int y) {
        return R[x] < R[y];
    });
    DFS(P[1]);
    build();
    for (scanf("%d", &q); q; q--) {
        solve();
    }
    return 0;
}
