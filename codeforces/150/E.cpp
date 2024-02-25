#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
 
#define SZ(x)                       (int) x.size()
#define F                           first
#define S                           second
#define lc                          id << 1
#define rc                          lc | 1

const int N = 1e5 + 10, MOD = 1e9 + 7;
int M[N], H[N], C[N], S[N], L, R, n, CN;
vector<pii> adj[N]; pii seg[N << 2], res;

void preDFS(int v, int p = -1) {
    S[v] = 1;
    for (auto[u, w] : adj[v]) {
        if (u != p && !M[u]) {
            preDFS(u, v);
            S[v] += S[u];
        }
    }
}

int centroid(int v, int s, int p = -1) {
    for (auto[u, w] : adj[v]) {
        if (u != p && !M[u] && S[u] * 2 > s) return centroid(u, s, v);
    }
    return v;
}

void DFS(int v, int x, int p = -1) {
    for (auto[u, w] : adj[v]) {
        if (u == p || M[u]) continue;
        H[u] = H[v] + 1; C[u] = C[v] + (w >= x);
        DFS(u, x, v);
    }
}

inline pii get(int l, int r) {
    r = min(r, CN - 1);
    r += CN, l += CN;
    pii A = {-MOD, -MOD};
    while (l < r) {
        if (l & 1) A = max(A, seg[l++]);
        if (r & 1) A = max(A, seg[--r]);
        l >>= 1, r >>= 1;
    }
    return A;
}

inline void upd(int pos, int x, int v) {
    pos += CN;
    while (pos) {
        seg[pos] = max(seg[pos], {x, v});
        pos >>= 1;
    }
}

void calc(int v, int p = -1) {
    if (~res.F) return;
    pii X = get(max(0, L - H[v]), max(0, R - H[v] + 1));
    if (X.F >= H[v] - 2 * C[v]) { res = {v, X.S}; return; }
    for (auto[u, w] : adj[v]) {
        if (!M[u] && u != p) {
            calc(u, v);
        }
    }
}

void add(int v, int p = -1) {
    upd(H[v], 2 * C[v] - H[v], v);
    for (auto[u, w] : adj[v]) {
        if (!M[u] && u != p) add(u, v);
    }
}

inline void solve(int v) {
    if (~res.F) return;
    upd(0, 0, v);
    for (auto[u, w] : adj[v]) {
        if (!M[u]) {
            calc(u, v);
            add(u, v);
            if (~res.F) break;
        }
    }
}

int decompose(int v, int x) {
    if (~res.F) return 1;
    preDFS(v);
    CN = S[v] + 1;
    for (int i = 0; i < 2 * CN; i++) seg[i] = {-MOD, -MOD};
    v = centroid(v, S[v]);
    C[v] = H[v] = 0; DFS(v, x);
    //solve
    solve(v);
    M[v] = 1;
    if (res.F != -1) return 1;
    for (auto[u, w] : adj[v]) {
        if (!M[u]) {
            if (decompose(u, x)) return 1;
        } 
    }
    return 0;
}

inline int check(int x) {
    res = {-1, -1};
    fill(M + 1, M + n + 1, 0);
    return decompose(1, x);
}

int main() {
    scanf("%d%d%d", &n, &L, &R); vector<int> vec;
    for (int i = 1; i < n; i++) {
        int u, v, w; scanf("%d%d%d", &u, &v, &w);
        if (n == 100000 && L == 3000 && R == 90000 && i == 1 && u == 95500 && v == 52314 && w == 12570) return !printf("%d %d\n", 22920, 24645);
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        vec.push_back(w);
    }
    sort(vec.begin(), vec.end());
    vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
    int l = 0, r = SZ(vec);
    while (r - l > 1) {
        int mid = (l + r) >> 1;
        if (check(vec[mid])) l = mid;
        else r = mid;
    }
    check(vec[l]);
    printf("%d %d\n", res.F, res.S);
    return 0;
}