/* I do it for the glory */
#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#pragma GCC target("sse,sse2,avx2,fma")

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
 
#define SZ(x)                       (int) x.size()
#define F                           first
#define S                           second

int Pow(int a, int b, int md, int ret = 1) {
    for (; b; b >>= 1, a = 1ll * a * a % md) 
        if (b & 1) ret = 1ll * ret * a % md;
    return ret;
}

const int N = 3e3 + 10, MOD = 998244353, L = 11;
int dp[N][N], pd[2][N][1 << L], ret[N], I[N], C[N], pw[N], A[N], n, c;

inline int nima(int x) {
    if (x >= MOD) x -= MOD;
    if (x < 0) x += MOD;
    return x;
}

void case_1() {
    pd[0][0][0] = 1; int X = (1 << c) - 1;
    for (int i = 1; i <= n; i++) 
        A[i]--;
    for (int i = 1; i <= n; i++) {
        int b = (i & 1), ob = 1 - b;
        for (int j = 0; j <= i / c; j++) {
            pd[b][j][0] = pd[ob][j][0];
            if (j) pd[b][j][0] = nima(pd[ob][j - 1][X ^ (1 << A[i])] + pd[b][j][0]);
            for (int msk = 1; msk < X; msk++) {
                pd[b][j][msk] = pd[ob][j][msk];
                if (msk >> A[i] & 1) 
                    pd[b][j][msk] = nima(pd[b][j][msk] + nima(pd[ob][j][msk ^ (1 << A[i])] + pd[ob][j][msk]));
            }
        }
    }
    for (int i = 0; i <= n / c; i++) 
            for (int k = 0; k < X; k++) 
                ret[i] = nima(ret[i] + pd[n & 1][i][k]);
    ret[0]--;
    for (int i = 0; i <= n; i++) 
        printf("%d ", ret[i]);
    printf("\n");
}

void case_2() {
    dp[0][0] = 1;
    for (int j = 0; j < n; j++) {
        int F = 1, cnt = c;
        for (int k = j + 1; k <= n; k++) {
            cnt -= !C[A[k]]; C[A[k]]++; F = 1ll * F * I[C[A[k]] - 1] % MOD;
            for (int i = 0; i < j / c + 1; i++) 
                if (!cnt) dp[k][i + 1] = nima(dp[k][i + 1] + dp[j][i] * 1ll * F % MOD);
            F = 1ll * F * (pw[C[A[k]]] - 1) % MOD;
        }
        for (int k = j + 1; k <= n; k++) C[A[k]] = 0;
    }
    int Fk = 1, F = 1, cnt = c;
    for (int j = n; ~j; j--) {
        for (int i = 0; i <= n / c; i++) 
            ret[i] = nima(ret[i] + dp[j][i] * 1ll * nima(Fk - (cnt ? 0 : F)) % MOD);
        cnt -= !C[A[j]]; C[A[j]]++; Fk = nima(Fk + Fk);
        F = 1ll * F * I[C[A[j]] - 1] % MOD * (pw[C[A[j]]] - 1) % MOD;
    }
    ret[0]--;
    for (int i = 0; i <= n; i++) printf("%d ", ret[i]);
    printf("\n");
}

int main() {
    pw[0] = I[0] = 1;
    for (int i = 1; i < N; i++) 
        pw[i] = nima(pw[i - 1] + pw[i - 1]);
    for (int i = 1; i < N; i++) 
        I[i] = Pow(pw[i] - 1, MOD - 2, MOD);
    scanf("%d%d", &n, &c);
    for (int i = 1; i <= n; i++) 
        scanf("%d", &A[i]);
    if (c <= L) case_1();
    else case_2();
    return 0;
}

