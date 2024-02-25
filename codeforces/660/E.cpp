/* I do it for the glory */
#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
 
#define SZ(x)                       (int) x.size()
#define F                           first
#define S                           second

const int N = 1e6 + 10, MOD = 1e9 + 7;
int n, m, pw[2][N];

int main() {
    scanf("%d%d", &n, &m);
    pw[0][0] = pw[1][0] = 1;
    for (int i = 1; i < N; i++) { 
        pw[0][i] = 1ll * pw[0][i - 1] * m % MOD;
        pw[1][i] = 1ll * pw[1][i - 1] * (m + m - 1) % MOD;
    }
    int ret = pw[0][n];
    for (int i = 0; i < n; i++) {
        ret = (ret + 1ll * pw[0][i + 1] * pw[1][n - i - 1] % MOD) % MOD;
    }
    printf("%d\n", ret);
    return 0;
}

