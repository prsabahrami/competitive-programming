/* I do it for the glory */
#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
 
#define SZ(x) (int) x.size()
#define F first
#define S second
#define lc id << 1
#define rc lc | 1

const int N = 1e6 + 10, MOD = 1e9 + 7;
char S[N]; int n, dp[N], C[N], seg[N << 2];

void bld(int id = 1, int l = 1, int r = n + 1) {
    if (r - l < 2) { seg[id] = C[l]; return; }
    int md = (l + r) >> 1;
    bld(lc, l, md), bld(rc, md, r);
    seg[id] = max(seg[lc], seg[rc]);
}

int bs(int ql, int qr, int x, int id = 1, int l = 1, int r = n + 1) {
    if (qr <= l || r <= ql || seg[id] < x) return 0;
    if (r - l < 2) return l;
    int md = (l + r) >> 1;
    int y = bs(ql, qr, x, rc, md, r);
    if (!y) return bs(ql, qr, x, lc, l, md);
    return y;
}

int main() {
    scanf("%s", S + 1); n = strlen(S + 1);
    int c = 0;
    for (; n && S[n] ^ '1'; n--, c++);
    if (!n) return !printf("%d\n", c);
    for (int i = n; i; i--) {
        if (S[i] ^ '1') 
            C[i] = C[i + 1] + 1;
        else C[i] = 0;
    }
    //~ for (int i = 1; i <= n; i++) 
        //~ printf("%d ", C[i]);
    //~ printf("\n");
    bld(); int lst = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = (dp[bs(1, i, C[i] + 1)] + dp[lst]) % MOD;
        if (C[i] <= C[1]) dp[i]++;
        if (!C[i]) lst = i;
        //~ printf("%d ", dp[i]);
    }
    //~ printf("\n");
    int ret = dp[n];
    ret = 1ll * (c + 1) * ret % MOD;
    printf("%d\n", ret);
    return 0;
}

