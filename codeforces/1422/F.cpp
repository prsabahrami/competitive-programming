/* Just a drop of water in an endless sea */
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,sse4")
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

const int N = 2e5 + 10, MOD = 1e9 + 7, SQ = 450;
vector<pii> seg[N << 2]; int A[N], pw[SQ][19], M[N], bp[N], n, q, ret; 
struct node; vector<shared_ptr<node>> tof;

struct node {
    int d; node *lc, *rc;
    
    node() : d(1), lc(this), rc(this) {};
    
    node* upd(int p, int x, int l = 1, int r = n + 1) {
        //tof.push_back(make_shared<node>(*this));
        node *nw = new node(*this);
        if (r - l < 2) { nw->d = 1ll * nw->d * x % MOD; return nw; }
        int md = (l + r) >> 1;
        if (p < md) nw->lc = lc->upd(p, x, l, md);
        else nw->rc = rc->upd(p, x, md, r);
        nw->d = 1ll * nw->lc->d * nw->rc->d % MOD;
        return nw;
    }
    
    int get(int ql, int qr, int l = 1, int r = n + 1) {
        if (qr <= l || r <= ql) return 1;
        if (ql <= l && r <= qr) return d;
        int md = (l + r) >> 1;
        return 1ll * lc->get(ql, qr, l, md) * rc->get(ql, qr, md, r) % MOD;
    }
} *rt[N];

void bld(int id = 1, int l = 1, int r = n + 1) {
    unordered_map<int, int> mp;
    for (int i = l; i < r; i++) {
        for (int x = A[i]; x > 1;) {
            int c = 0, y = bp[x];
            for (; bp[x] == y; x /= bp[x], c++);
            if (c > 1) mp[y] = max(mp[y], c);
        }
    }
    for (pii x : mp) seg[id].push_back(x);
    if (r - l < 2) return;
    int md = (l + r) >> 1;
    bld(id << 1, l, md), bld(id << 1 | 1, md, r);
}

void get(int ql, int qr, int id = 1, int l = 1, int r = n + 1) {
    if (qr <= l || r <= ql) return;
    if (ql <= l && r <= qr) {
        for (pii &x : seg[id]) 
            if (x.S > M[x.F]) ret = 1ll * ret * pw[x.F][x.S - M[x.F]] % MOD, M[x.F] = x.S;
        return;
    }
    int md = (l + r) >> 1;
    get(ql, qr, id << 1, l, md), get(ql, qr, id << 1 | 1, md, r);
}

int main() {
    for (int i = 1; i < SQ; i++) 
        for (int j = 0; j < 19; j++) 
            pw[i][j] = j ? i * 1ll * pw[i][j - 1] % MOD : 1;
    for (int i = 2; i < N; i++) 
        if (!bp[i]) for (int j = i; j < N; j += i) bp[j] = i;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) 
        scanf("%d", &A[i]);
    rt[0] = new node();
    for (int i = 1; i <= n; i++) {
        rt[i] = rt[i - 1];
        for (int x = A[i]; x > 1; x /= bp[x]) 
            if (bp[x] != bp[x / bp[x]]) {
                rt[i] = rt[i]->upd(i, bp[x]); 
                if (M[bp[x]]) rt[i] = rt[i]->upd(M[bp[x]], Pow(bp[x], MOD - 2, MOD)); 
                M[bp[x]] = i;
            }
    }
    memset(M, 0, sizeof M);
    bld();
    fill(M, M + N, 1);
    for (scanf("%d", &q); q; q--) {
        int l, r; scanf("%d%d", &l, &r);
        l = (l + ret) % n + 1, r = (r + ret) % n + 1;
        if (r < l) swap(l, r);
        ret = rt[r]->get(l, r + 1);
        get(l, r + 1);
        printf("%d\n", ret);
        for (int i = 0; i < SQ; i++) M[i] = 1;
    }
    return 0;
}