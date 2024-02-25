/* I do it for the glory */
#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
 
#define SZ(x)                       (int) x.size()
#define F                           first
#define S                           second

const int N = 5e3 + 10, MOD = 1e9 + 7;
ll dp[N][N]; int A[N], B[N], X[N], C[N], D[N], n, s, e;

int main() {
    scanf("%d%d%d", &n, &s, &e);
    for (int i = 1; i <= n; i++) 
        scanf("%d", &X[i]);
    for (int i = 1; i <= n; i++) 
        scanf("%d", &A[i]);
    for (int i = 1; i <= n; i++) 
        scanf("%d", &B[i]);
    for (int i = 1; i <= n; i++) 
        scanf("%d", &C[i]);
    for (int i = 1; i <= n; i++) 
        scanf("%d", &D[i]);
    for (int i = 0; i < N; i++) 
        for (int j = 0; j < N; j++) dp[i][j] = 1e17;
    dp[1][1] = 2ll * -X[1] + B[1] + D[1]; 
    if (s < 2) dp[1][1] = -X[1] + D[1];
    if (e < 2) dp[1][1] = -X[1] + B[1];
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == s) {
                dp[i][j] = dp[i - 1][j - 1] - X[i] + D[i];
                if (i < e || j > 1 || i == n) dp[i][j] = min(dp[i][j], dp[i - 1][j] + X[i] + C[i]);
            }
            else if (i == e) {
                dp[i][j] = dp[i - 1][j - 1] - X[i] + B[i];
                if (i < s || j > 1 || i == n) dp[i][j] = min(dp[i][j], dp[i - 1][j] + X[i] + A[i]);
            }
            else {
                dp[i][j] = dp[i - 1][j - 1] - 2ll * X[i] + B[i] + D[i];
                if (i < s || i < e || j > 1 || i == n) dp[i][j] = min(dp[i][j], dp[i - 1][j + 1] + 2ll * X[i] + A[i] + C[i]);
                if (j > 1 || (i < s && i < e)) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j] + min(A[i] + D[i], C[i] + B[i]));
                } else if (i > s && i < e) dp[i][j] = min(dp[i][j], dp[i - 1][j] + A[i] + D[i]);
                else if (i < s && i > e) dp[i][j] = min(dp[i][j], dp[i - 1][j] + C[i] + B[i]);
            }
        }
    }
    printf("%lld\n", dp[n][1]);
    return 0;
}

