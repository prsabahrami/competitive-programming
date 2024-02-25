/* Just a drop of water in an endless sea */
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

const int N = 1e6 + 10, MOD = 998244353;
int t, n, F[N], I[N], A[N];

int C(int x, int y) { 
    if (x < y || y < 0) return 0;
    return 1ll * F[x] * I[y] % MOD * I[x - y] % MOD;
}

int main() {
    F[0] = 1;
    for (int i = 1; i < N; i++) 
        F[i] = 1ll * i * F[i - 1] % MOD;
    I[N - 1] = Pow(F[N - 1], MOD - 2, MOD);
    for (int i = N - 1; i; i--) 
        I[i - 1] = 1ll * i * I[i] % MOD;
    for (scanf("%d", &t); t; t--) {
        scanf("%d", &n); int mx = 0;
        for (int i = 1; i <= n; i++) 
            scanf("%d", &A[i]), mx = max(mx, A[i]);
        int c = 0;
        for (int i = 1; i <= n; i++) 
            if (A[i] == mx) c++;
        if (c > 1) { printf("%d\n", F[n]); continue; }
        c = 0;
        for (int i = 1; i <= n; i++) 
            if (A[i] < mx - 1) c++;
        int ret = 0;
        for (int i = 1; i <= n; i++) 
            ret = (ret + 1ll * F[i - 1] * C(c, n - i) % MOD * F[n - i] % MOD) % MOD;
        ret = (F[n] - ret + MOD) % MOD;
        printf("%d\n", ret);
    }
    return 0;
}

