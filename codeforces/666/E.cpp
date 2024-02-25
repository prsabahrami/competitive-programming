#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;

#define SZ(x) (int) (x).size()
#define F first
#define S second
#define lc id << 1
#define rc lc | 1

const int N = 6e5 + 10, MOD = 1e9 + 7, SQ = 300;
int rnk[20][N], P[N], lcp[N], seg[N << 2], rt[N], n, q, m;
char T[N]; string S[N]; pii pr[N], mx[N << 2], ret[N]; int tL, L[N], R[N], pos[N]; array<int, 3> Q[N];

void bldSA() {
    for (m = 1; T[m]; m++) rnk[0][P[m] = m] = T[m];
    m--;
    for (int pw = 1; pw < 20; pw++) {
        for (int i = 1; i <= m; i++) 
            pr[i] = {rnk[pw - 1][i], i + (1 << (pw - 1)) > m ? 0 : rnk[pw - 1][i + (1 << (pw - 1))]};
        sort(P + 1, P + m + 1, [&] (int x, int y) { return pr[x] < pr[y]; });
        rnk[pw][P[1]] = 1;
        for (int i = 2; i <= m; i++) 
            rnk[pw][P[i]] = rnk[pw][P[i - 1]] + (pr[P[i]] != pr[P[i - 1]]);
    }
}

int LCP(int x, int y) {
    if (x > y) swap(x, y);
    int ans = 0;
    for (int i = 19; ~i; i--) {
        if (y + ans + (1 << i) > m + 1) continue;
        if (rnk[i][x + ans] == rnk[i][y + ans]) ans += (1 << i);
    }
    return ans;
}

void bld(int id = 1, int l = 1, int r = m) {
    if (r - l < 2) { seg[id] = lcp[l]; return; }
    int md = (l + r) >> 1;
    bld(lc, l, md), bld(rc, md, r);
    seg[id] = min(seg[lc], seg[rc]);
}

int bs(int p, int x, int id = 1, int l = 1, int r = m) {
    if (tL && p < l) return 0;
    if (!tL && p >= r) return m;
    if (seg[id] >= x) return tL ? 0 : m;
    if (r - l < 2) return l;
    int md = (l + r) >> 1, y;
    y = !tL ? bs(p, x, lc, l, md) : bs(p, x, rc, md, r);
    if (y > 0 && y < m) return y;
    return tL ? bs(p, x, lc, l, md) : bs(p, x, rc, md, r);
}

void pre() {
    for (int i = n + 2; i <= 2 * n + 5; i++) 
        mx[i] = {0, -(i - n - 1)};
    for (int i = n + 1; i; i--) 
        mx[i] = max(mx[i << 1], mx[i << 1 | 1]);
}

void upd(int p, int x) {
    for (mx[p += n + 1].F += x; p > 1; p >>= 1) mx[p >> 1] = max(mx[p], mx[p ^ 1]);
}

void add(int x) { if (rt[P[x]]) upd(rt[P[x]], 1); }

void rem(int x) { if (rt[P[x]]) upd(rt[P[x]], -1); }

pii get(int l, int r) {
    pii ans = {-MOD, -MOD};
    for (l += n + 1, r += n + 1; l < r; l >>= 1, r >>= 1) {
        if (l & 1) ans = max(ans, mx[l++]);
        if (r & 1) ans = max(ans, mx[--r]);
    }
    return ans;
}

int main() {
    scanf("%s", T + 1); scanf("%d", &n); S[0] = T + 1;
    for (int i = 1; i <= n; i++) {
        scanf("%s", T + 1), S[i] = T + 1;
    }
    for (int pt = 1, i = 0; i <= n; i++) {
        for (int j = 0; j < SZ(S[i]); j++) 
            T[pt++] = S[i][j], rt[pt - 1] = i;
        T[pt++] = '$';
    }
    bldSA();
    for (int i = 1; i <= m; i++) 
        pos[P[i]] = i;
    for (int i = 1; i < m; i++) lcp[i] = LCP(P[i], P[i + 1]);
    bld();
    scanf("%d", &q);
    for (int i = 1; i <= q; i++) {
        int l, r, _l, _r; scanf("%d%d%d%d", &l, &r, &_l, &_r);
        tL = 1; int ql = bs(pos[_l] - 1, _r - _l + 1) + 1;
        tL = 0; int qr = bs(pos[_l], _r - _l + 1);
        Q[i] = {ql, qr, i}; L[i] = l, R[i] = r;
    }
    sort(Q + 1, Q + q + 1, [&] (array<int, 3> X, array<int, 3> Y) {
        if (X[0] / SQ != Y[0] / SQ) return X[0] < Y[0];
        return X[1] < Y[1];
    });
    int ml = 0, mr = 0; pre();
    for (int i = 1; i <= q; i++) {
        while (ml < Q[i][0]) rem(ml++);
        while (ml > Q[i][0]) add(--ml);
        while (mr > Q[i][1]) rem(mr--);
        while (mr < Q[i][1]) add(++mr);
        ret[Q[i][2]] = get(L[Q[i][2]], R[Q[i][2]] + 1);
        //if (!ret[Q[i][2]].F) ret[Q[i][2]].S = -L[Q[i][2]];
    }
    for (int i = 1; i <= q; i++) printf("%d %d\n", -ret[i].S, ret[i].F);
    return 0;
}