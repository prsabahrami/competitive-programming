#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
 
#define SZ(x)                       (int) x.size()
#define F                           first
#define S                           second
int Pow(int a, int b, int md, int res = 1) {
    for (; b; b >>= 1, a = 1ll * a * a % md) {
        if (b & 1) res = 1ll * res * a % md;
    }
    return res;
}

const int N = 1e5 + 10, MOD = 1e9 + 7;
int H[N], inv[N], pw[N], S[N], M[N], D[N], U[N], n, m, phi;
vector<pii> adj[N]; ll R = 0; map<int, int> mp;

void sDFS(int v, int p = -1) {
    S[v] = 1;
    for (pii u : adj[v]) {
        if (u.F != p && !M[u.F]) sDFS(u.F, v), S[v] += S[u.F];
    }
}

void DFS(int v, int p = 0) {
    for (pii nei : adj[v]) {
        int u = nei.F, w = nei.S;
        if (u != p && !M[u]) {
            H[u] = H[v] + 1;
            U[u] = (U[v] + 1ll * pw[H[u] - 1] * w % m) % m;
            D[u] = (1ll * D[v] * 10 + w) % m;
            DFS(u, v); 
        }
    }
}

int centroid(int v, int s, int p = 0) {
    for (pii nei : adj[v]) {
        int u = nei.F;
        if (u != p && !M[u] && S[u] * 2 > s) {
            return centroid(u, s, v);
        }
    }
    return v;
}

void preDFS(int v, int p = -1) {
    mp[U[v]]++;
    for (pii nei : adj[v]) {
        int u = nei.F;
        if (u != p && !M[u]) {
            preDFS(u, v);
        }
    }
}

ll cDFS(int v, int p = -1) {
    ll res = 0;
    for (pii nei : adj[v]) {
        int u = nei.F;
        if (u != p && !M[u]) res += cDFS(u, v);
    }
    mp[U[v]]--;
    res += mp[1ll * (m - D[v]) * inv[H[v]] % m];
    mp[U[v]]++;
    return res;
}

void solve(int v) {
    mp.clear();
    preDFS(v);
    R += cDFS(v);
    for (pii nei : adj[v]) {
        int u = nei.F;
        if (!M[u]) {
            mp.clear();
            preDFS(u, v);
            R -= cDFS(u, v);
        }
    }
}

void decompose(int v) {
    sDFS(v);
    v = centroid(v, S[v]);
    H[v] = U[v] = D[v] = 0;
    DFS(v);
    // solve
    solve(v);
    M[v] = 1;
    for (pii nei : adj[v]) {
        int u = nei.F;
        if (!M[u]) decompose(u);
    }
}

void init() {
    phi = m;
    int t = m;
    for (int i = 2; i * i <= t; i++) {
        if (t % i) continue;
        while (t % i == 0) t /= i;
        phi -= phi / i;
    }
    if (t > 1) phi -= phi / t;
    phi--;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i < n; i++) {
        int u, v, w; scanf("%d%d%d", &u, &v, &w);
        u++, v++;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    init();
    pw[0] = inv[0] = 1;
    for (int i = 1; i < N; i++) {
        pw[i] = 1ll * pw[i - 1] * 10 % m;
        inv[i] = Pow(pw[i], phi, m);
    }
    decompose(1);
    printf("%lld\n", R);
	return 0;
}
