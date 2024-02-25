#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;
 
#define SZ(x)                       (ll) x.size()
#define F                           first
#define S                           second

ll Pow(ll a, ll b, ll md, ll ans = 1) {
    for (; b; b >>= 1, a = a * a % md)
        if (b & 1)
            ans = ans * a % md;
    return ans % md;
}

const ll N = 1e6 + 10, MOD = 998244353;
ll dp[N], n;

int main() {
	scanf("%lld", &n);
	dp[1] = Pow(2, MOD - 2, MOD), dp[2] = dp[3] = Pow(4, MOD - 2, MOD);
	for (int i = 4; i <= n; i++) {
		dp[i] = (dp[i - 2] * Pow(4, MOD - 2, MOD) + dp[i - 1] * Pow(2, MOD - 2, MOD)) % MOD;
	}
	printf("%lld\n", dp[n]);
    return 0;
}

