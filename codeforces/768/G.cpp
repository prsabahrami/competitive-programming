/* I do it for the glory */
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
 
#define SZ(x) (int) x.size()
#define F first
#define S second

const int N = 1e5 + 10, MOD = 1e9 + 7;
int St[N], L[N], Md[N], R[N], P[N], Ft[N], S[N], hv[N], M[N], mx[2][N], mn[N], n, rt, ts;
vector<int> adj[N], vec[N], pbs[N]; vector<int> p; int val[N];
struct hmm {
    int seg[N << 2];

    void bld() {
        for (int i = 0; i < 2 * ts + 5; i++) seg[i] = MOD;
    }

    void upd(int pt, int x) {
        for (pt += ts + 1; pt; pt >>= 1) {
            seg[pt] = min(seg[pt], x);
        }
    }

    int get(int l, int r) {
        int ret = MOD;
        for (r += ts + 1, l += ts + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) ret = min(ret, seg[l++]);
            if (r & 1) ret = min(ret, seg[--r]);
        }
        return ret;
    }

};
hmm A, B;

void preDFS(int v) {
    S[v] = 1; St[v] = ts++;
    for (int &u : adj[v]) 
        preDFS(u), S[v] += S[u];
    mx[0][v] = mn[v] = n - S[v];
    if (v == rt) mn[v] = MOD;
    for (int &u : adj[v]) {
        if (S[u] > S[hv[v]]) hv[v] = u;
        if (S[u] > mx[1][v]) mx[1][v] = S[u];
        if (mx[0][v] < mx[1][v]) swap(mx[1][v], mx[0][v]);
        if (S[u] < mn[v]) mn[v] = S[u];
    }
    if (S[hv[v]] < n - S[v]) hv[v] = P[v];
    if (S[v] < 2 || (v == rt && SZ(adj[v]) < 2)) L[v] = R[v] = n - 1;
    Ft[v] = ts++;
}

void DFS(int v) {
    if (hv[v] == P[v] && !M[v] && R[v] - L[v] > 1 && SZ(p)) {
        int l = 0, r = SZ(p);
        while (r - l > 1) {
            int md = (l + r) >> 1;
            if (p[md] >= mx[0][v] - Md[v] + S[v]) l = md;
            else r = md;
        }
        if (p[l] >= mx[0][v] - Md[v] + S[v]) 
            val[v] = min(val[v], p[l] - S[v]);
    }
    if (v ^ rt) p.push_back(S[v]);
    for (int &u : adj[v]) 
        DFS(u);
    if (v ^ rt) p.pop_back();
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int u, v; scanf("%d%d", &u, &v);
        if (u) adj[P[v] = u].push_back(v);
        else rt = v;
    }
    preDFS(rt);
    for (int i = 1; i <= n; i++) {
        if (R[i]) continue;
        L[i] = 0, R[i] = n + 1;
        if (mx[0][i] == mx[1][i]) L[i] = R[i] = mx[0][i];
    }
    for (int i = 1; i <= n; i++) 
        vec[S[i]].push_back(i), val[i] = MOD;
    for (int _ = 0; _ < 17; _++) {
        A.bld(), B.bld();
        fill(M, M + n + 1, 0); int f = 0;
        for (int i = 1; i <= n; i++) {
            if (R[i] - L[i] < 2) continue;
            Md[i] = (L[i] + R[i]) >> 1;
            if (Md[i] >= mx[0][i]) R[i] = Md[i], M[i] = 1;
            else if (Md[i] < mx[1][i]) L[i] = Md[i], M[i] = 1;
            else pbs[mx[0][i] - Md[i]].push_back(i), f = 1;
        }
        if (!f) break;
        for (int i = n; i; i--) {
            for (int &id : vec[i]) A.upd(St[id], i), B.upd(Ft[id], i);
            for (int &v : pbs[i]) {
                if (hv[v] ^ P[v]) {
                    int x = A.get(St[hv[v]], Ft[hv[v]]);
                    if (mn[v] + x <= Md[v]) R[v] = Md[v];
                    else L[v] = Md[v];
                } else {
                    val[v] = min(B.get(0, St[v]), A.get(Ft[v], ts));
                }
            }
            pbs[i] = {};
        }
        p = {};
        DFS(rt);
        for (int i = 1; i <= n; i++) {
            if (hv[i] ^ P[i] || M[i] || R[i] - L[i] < 2) continue;
            if (mn[i] + val[i] <= Md[i]) R[i] = Md[i];
            else L[i] = Md[i];
            val[i] = MOD;
        }
    }
    for (int i = 1; i <= n; i++) printf("%d\n", R[i]);
    return 0;
}

