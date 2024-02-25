/* I do it for the glory */
#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
 
#define SZ(x)                       (int) x.size()
#define F                           first
#define S                           second

const int N = 21;
int C[N][N], pd[N][N][N], dp[N][1 << N], md, n, m, E[1 << N], B[N]; ll t;

int add(int x, int y) {
    x += y;
    if (x >= md) x -= md;
    return x;
}

struct Matrix {
    int A[N];

    Matrix() { memset(A, 0, sizeof A); }

    int& operator[](int i) { return A[i]; }

    friend Matrix operator*(Matrix &x, Matrix &y) {
        Matrix z;
        for (int i = 0; i <= m; i++) 
            for (int j = 0; j <= m; j++) 
                for (int k = 0; k <= m; k++) {
                    z[i] = add(z[i], 1ll * x[j] * y[k] % md * pd[i][j][k] % md);
                }
        return z;
    }

    friend Matrix operator^(Matrix x, ll y) {
        Matrix ret = x;
        if (y < 0) return ret;
        for (; y; y >>= 1, x = x * x) {
            if (y & 1) ret = ret * x;
        }
        return ret;
    }
};

int main() {
    scanf("%d%lld%d", &m, &t, &md);
    n = 1 << m;
    for (int i = 0; i < n; i++) 
        scanf("%d", &E[i]), E[i] %= md;
    for (int i = 0; i <= m; i++) 
        scanf("%d", &B[i]), B[i] %= md;
    for (int i = 0; i < n; i++) 
        dp[0][i] = E[i];
    for (int i = 0; i < m; i++) 
        for (int k = m; k; k--) 
            for (int j = 0; j < n; j++) 
                    dp[k][j] = add(dp[k][j], dp[k - 1][j ^ (1 << i)]);
    for (int i = 0; i < N; i++) 
        for (int j = 0; j < N; j++) {
            if (i < j) continue;
            if (!j) C[i][j] = 1;
            else C[i][j] = add(C[i - 1][j], C[i - 1][j - 1]);
        }
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= m; j++) {
            for (int k = 0; k <= i; k++) {
                if (k > j) continue;
                int nw = i + j - 2 * k;
                if (nw > m) continue;
                pd[i][j][nw] = add(pd[i][j][nw], C[i][k] * 1ll * C[m - i][j - k] % md);
            }
        }
    }
    Matrix A;
    for (int i = 0; i <= m; i++) 
        A[i] = B[i];
    A = A ^ (t - 1);
    for (int i = 0; i < n; i++) {
        int ret = 0;
        for (int j = 0; j <= m; j++) {
            ret = add(ret, 1ll * dp[j][i] * A[j] % md);
        }
        printf("%d\n", ret);
    }
    return 0;
}

