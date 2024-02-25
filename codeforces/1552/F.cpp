/* I do it for the glory */
#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
 
#define SZ(x) (int) x.size()
#define F first
#define S second

const int N = 1e6 + 10, MOD = 998244353;
int n, X[N], Y[N], dp[N], M[N], ps[N];
vector<int> cp;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) 
        scanf("%d%d%d", &X[i], &Y[i], &M[i]);
    int ret = 0;
    for (int i = 1; i <= n; i++) {
        int p = lower_bound(X + 1, X + n + 1, Y[i]) - X;
        dp[i] = (ps[i - 1] - ps[p - 1] + MOD) % MOD;
        dp[i] = (dp[i] + X[i] - Y[i]) % MOD;
        ps[i] = (ps[i - 1] + dp[i]) % MOD;
        ret = (ret + X[i] - X[i - 1]) % MOD;
        if (M[i]) ret = (ret + dp[i]) % MOD;
    }
    printf("%d\n", (ret + 1) % MOD);
    return 0;
}

