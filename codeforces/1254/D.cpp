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

const int N = 1.5e5 + 10, MOD = 998244353, LOG = 21, SQ = 600;
int E[N], S[N], P[LOG][N], H[N], A[N], ps[N], St[N], Ft[N], D[N], n, q, tim, invn;
vector<int> adj[N]; vector<pii> Q;

void add(int l, int r, int val) {
    ps[l] = (ps[l] + val) % MOD;
    ps[r] = (ps[r] + MOD - val) % MOD;
}

void preDFS(int v, int p = 0) {
    St[v] = tim++; S[v] = 1; E[St[v]] = v;
    if (!p) P[0][v] = v;
    for (int i = 1; i < LOG; i++) {
        P[i][v] = P[i - 1][P[i - 1][v]];
    }
    for (int u : adj[v]) {
        if (u != p) {
            H[u] = H[v] + 1, P[0][u] = v;
            preDFS(u, v);
            S[v] += S[u];
        }
    }
    Ft[v] = tim;
}

int getpar(int v, int h) {
    for (int i = LOG; i--;) if (h & (1 << i)) v = P[i][v];
    return v;
}

void relax() {
    if (!SZ(Q)) return;
    for (pii x : Q) {
        int p = x.F, d = x.S;
        D[p] = (D[p] + d) % MOD;
    }
    for (int v = 1; v <= n; v++) {
        if (!D[v]) continue;
        A[v] = (A[v] + D[v]) % MOD;
        for (int u : adj[v]) {
            if (u == P[0][v]) continue;
            add(St[u], Ft[u], 1ll * D[v] * (n - S[u]) % MOD * invn % MOD);
        }
        add(St[1], St[v], 1ll * D[v] * S[v] % MOD * invn % MOD);
        add(Ft[v], Ft[1], 1ll * D[v] * S[v] % MOD * invn % MOD);
        D[v] = 0;
    }
    for (int i = 0; i < tim; i++) {
        ps[i + 1] = (ps[i + 1] + ps[i]) % MOD;
        A[E[i]] = (A[E[i]] + ps[i]) % MOD;
        ps[i] = 0;
    }
    Q = {};
}

int main() {
    scanf("%d%d", &n, &q);
    invn = Pow(n, MOD - 2, MOD);
    for (int i = 1; i < n; i++) {
        int u, v; scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    preDFS(1);
    for (; q; q--) {
        if (q % SQ == 0) relax();
        int t, v, d; scanf("%d%d", &t, &v);
        if (t == 1) {
            scanf("%d", &d);
            Q.push_back({v, d});
        } else {
            int R = 0;
            for (pii x : Q) {
                int p = x.F; d = x.S;
                if (St[p] <= St[v] && Ft[v] <= Ft[p]) {
                    if (v == p) R = (R + d) % MOD; 
                    else {
                        int u = getpar(v, H[v] - H[p] - 1);
                        R = (R + 1ll * d * (n - S[u]) % MOD * invn % MOD) % MOD;
                    }
                }
                else R = (R + 1ll * d * S[p] % MOD * invn % MOD) % MOD;
            }
            printf("%d\n", (R + A[v]) % MOD);
        }
    }
    return 0;
}
