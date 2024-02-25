#include <bits/stdc++.h>
#pragma GCC optimize("O2")

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;
 
#define SZ(x)                       (ll) x.size()
#define F                           first
#define S                           second

const ll N = 3e3 + 10;
ll dp[N][N], T[N], n, k;
pair<ll, int> ps[N][N], M[N][N];

int main() {
	scanf("%lld%lld", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &T[i]);
		for (int j = 1; j <= T[i]; j++) {
			int x; scanf("%d", &x);
			if (j > k) continue;
			ps[j][i] = {ps[j - 1][i].F + x, i};
			M[i][j] = {ps[j][i].F, i};
		}
	}
	for (int i = 1; i <= k; i++) {
		sort(ps[i] + 1, ps[i] + n + 1, greater<pair<ll, int>>());
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			if (j >= 2 && M[i][j] < ps[j][k / j + 1]) continue;
			if (M[i][j].F == 0 && j) continue;
			for (int l = 0; l + j <= k; l++) {
				dp[i][l + j] = max(dp[i][l + j], dp[i - 1][l] + M[i][j].F);
			}
		}
	}
	printf("%lld\n", dp[n][k]);
    return 0;
}