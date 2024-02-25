#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
 
#define SZ(x) (int) x.size()
#define F first
#define S second
#define lc id << 1
#define rc lc | 1

const int N = 4e5 + 10, MOD = 1e9 + 7;
int n, St[2][N], P[2][N], Ft[2][N], ts; vector<int> adj[N], G[N]; vector<pii> vec[N];
vector<int> ret;

struct Goat {
    int L[N << 2], R[N << 2], M[N]; vector<pii> A[N << 2];

    Goat() {
        memset(L, 0, sizeof L), memset(R, 0, sizeof R);
        memset(M, 0, sizeof M);
    }

    void bld(int id = 1, int l = 0, int r = n) { // (L[id], R[id])
        if (r - l < 2) { A[id] = vec[l]; R[id] = SZ(A[id]) - 1; return; }
        int md = (l + r) >> 1;
        bld(lc, l, md), bld(rc, md, r);
        merge(begin(A[lc]), end(A[lc]), begin(A[rc]), end(A[rc]), back_inserter(A[id]));
        R[id] = SZ(A[id]) - 1;
    }

    void get(int ql, int qr, int tl, int tr, int id = 1, int l = 0, int r = n) { // [tl, tr]
        if (qr <= l || r <= ql) return;
        if (ql <= l && r <= qr) {
            for (; L[id] <= R[id] && A[id][L[id]].F <= tl; L[id]++) 
                if (!M[A[id][L[id]].S]) M[A[id][L[id]].S] = 1, ret.push_back(A[id][L[id]].S);
            for (; L[id] <= R[id] && A[id][R[id]].F >= tr; R[id]--) 
                if (!M[A[id][R[id]].S]) M[A[id][R[id]].S] = 1, ret.push_back(A[id][R[id]].S);
            return;
        }
        int md = (l + r) >> 1;
        get(ql, qr, tl, tr, lc, l, md), get(ql, qr, tl, tr, rc, md, r);
    }
} seg[2];

void DFS(int v, vector<int>* g, int t) {
    St[t][v] = ts++;
    for (int &u : g[v]) 
        P[t][u] = v, DFS(u, g, t);
    Ft[t][v] = ts;
}

int main() {
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
        int p; scanf("%d", &p);
        adj[p].push_back(i);
    }
    for (int i = 2; i <= n; i++) {
        int p; scanf("%d", &p);
        G[p].push_back(i);
    }
    DFS(1, adj, 0); ts = 0; DFS(1, G, 1);
    for (int i = 1; i <= n; i++) {
        for (int v : adj[i])
            vec[St[1][i]].push_back({St[1][v], v});
        if (i > 1) vec[St[1][i]].push_back({St[1][P[0][i]], i});
    }
    for (int i = 0; i < n; i++) 
        sort(begin(vec[i]), end(vec[i]));
    seg[0].bld();
    for (int i = 0; i <= n; i++) vec[i] = {};
    for (int i = 1; i <= n; i++) {
        for (int v : G[i])
            vec[St[0][i]].push_back({St[0][v], v});
        if (i > 1) vec[St[0][i]].push_back({St[0][P[1][i]], i});
    }
    for (int i = 0; i < n; i++) 
        sort(begin(vec[i]), end(vec[i]));
    seg[1].bld();
    int id, t = 1; scanf("%d", &id);
    ret.push_back(id + 1); seg[0].M[id + 1] = 1;
    for (; SZ(ret); t ^= 1) {
        printf(t ? "Blue\n" : "Red\n");
        sort(begin(ret), end(ret));
        for (int &x : ret) printf("%d ", x - 1);
        printf("\n");
        vector<int> tmp = ret; ret = {};
        for (int &x : tmp) {
            seg[t].get(St[t ^ 1][x], Ft[t ^ 1][x], St[t ^ 1][x] - 1, Ft[t ^ 1][x]);
        }
    }
    return 0;
}

