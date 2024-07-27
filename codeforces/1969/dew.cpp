#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long int ll;
typedef pair<int, int> pii;
 
#define F first
#define S second
#define lc id << 1
#define rc lc | 1
 
constexpr int N = 3e5 + 10, MOD = 1e9 + 7;
int dp[N], pd[N], A[N], lst[N], ret[N], seg[N << 2], n, q;

int get(int ql, int qr, int l = 0, int r = n + 1, int id = 1) {
    if (ql >= r || qr <= l || ql >= qr) return MOD;
    if (ql <= l && r <= qr) return seg[id];
    int mid = (l + r) >> 1;
    return min(get(ql, qr, l, mid, lc), get(ql, qr, mid, r, rc));
}

int upd(int p, int val, int l = 0, int r = n + 1, int id = 1) {
    if (r - l < 2) return seg[id] = val;
    int mid = (l + r) >> 1;
    if (p < mid) upd(p, val, l, mid, lc);
    else upd(p, val, mid, r, rc);
    return seg[id] = min(seg[lc], seg[rc]);
}

void clear(int l = 0, int r = n + 1, int id = 1) {
    if (r - l < 2) {
        seg[id] = MOD;
        return;
    }
    int mid = (l + r) >> 1;
    clear(l, mid, lc);
    clear(mid, r, rc);
    seg[id] = MOD;
}

int main() {
    for (scanf("%d", &q); q--;) {
        scanf("%d", &n);
        clear();
        for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
        pd[1] = 1;
        dp[1] = 1;
        ret[1] = 0;
        lst[A[1]] = 1;
        upd(1, 1);
        upd(0, 0);
        for (int i = 2; i <= n; i++) {
            dp[i] = lst[A[i]] + 1;
            if (dp[i] != i) {
                int x;
                if (lst[A[i]]) x = dp[lst[A[i]]];
                x = max(x, dp[i - 1]);
                dp[i] = min(dp[i], x);
            }
            pd[i] = max(pd[i - 1], dp[i]);
            ret[i] = min(1 + ret[i - 1], get(pd[i] - 1, i));
            lst[A[i]] = i;
            upd(i, ret[i - 1] + 1);
        }
        for (int i = 1; i <= n; i++) printf("%d ", dp[i]);
        printf("\n");
        for (int i = 1; i <= n; i++) printf("%d ", pd[i]);
        printf("\n");
        for (int i = 1; i <= n; i++) printf("%d ", ret[i]);
        printf("\n");
        printf("%d\n", ret[n]);
        for (int i = 1; i <= n; i++) pd[i] = dp[i] = ret[i] = lst[i] = 0;
    }
    return 0;
}
