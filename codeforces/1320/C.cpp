#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
 
#define SZ(x)                       (int) x.size()
#define F                           first
#define S                           second
#define lc                          id << 1
#define rc                          lc | 1

const int N = 1e6 + 10, MOD = 1e9 + 7;
ll seg[N << 2], lz[N << 2], M[N]; int A[N], B[N], C[N], D[N]; vector<int> vec[N], Q[N];
int n, m, p;

void build(int id = 1, int l = 0, int r = N) {
    if (r - l == 1) {
        seg[id] = M[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(lc, l, mid);
    build(rc, mid, r);
    seg[id] = max(seg[lc], seg[rc]);
}

void shift(int id, int l, int r) {
    seg[id] += lz[id];
    if (r - l > 1) {
        lz[lc] += lz[id];
        lz[rc] += lz[id];
    }
    lz[id] = 0;
}

void update(int ql, int qr, ll x, int id = 1, int l = 0, int r = N) {
    shift(id, l, r);
    if (qr <= l || r <= ql) return;
    if (ql <= l && r <= qr) {
        lz[id] += x;
        return shift(id, l, r);
    }
    int mid = (l + r) >> 1;
    update(ql, qr, x, lc, l, mid);
    update(ql, qr, x, rc, mid, r);
    seg[id] = max(seg[lc], seg[rc]);
}

int main() {
    fill(M, M + N, -1e18);
    scanf("%d%d%d", &n, &m, &p);
    for (int i = 1; i <= n; i++) {
        int a; scanf("%d%d", &a, &A[i]);
        vec[a].push_back(i);
    }
    for (int i = 1; i <= m; i++) {
        int b; scanf("%d%d", &b, &B[i]);
        M[b] = max(M[b], (ll) -B[i]);    
    }   
    build();
    for (int i = 1; i <= p; i++) {
        int x; scanf("%d%d%d", &x, &C[i], &D[i]);
        Q[x].push_back(i);
    }
    ll res = -1e18;
    for (int i = 0; i < N; i++) {
        for (int j : vec[i]) {
           res = max(res, seg[1] - A[j]);
        }
        for (int j : Q[i]) {
            update(C[j] + 1, N, D[j]);
        }
    }
    printf("%lld\n", res);
    return 0;
}
