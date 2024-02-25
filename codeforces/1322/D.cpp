#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
 
#define SZ(x)                       (int) x.size()
#define F                           first
#define S                           second

const int N = 4e3 + 10, MOD = 1e9 + 7;
ll dp[N][N]; int L[N], S[N], C[N], n, m;

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &L[i]);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &S[i]);
	}
	for (int i = 1; i <= n + m; i++) {
		scanf("%d", &C[i]);
	}
	for (int i = 1; i <= n + m; i++) {
		for (int j = 1; j <= n + 10; j++) dp[i][j] = 1ll * -MOD * MOD;
	}
	for (int i = n; i >= 1; i--) {
		for (int j = n; j >= 1; j--) {
			dp[L[i]][j] = max(dp[L[i]][j], dp[L[i]][j - 1] + C[L[i]] - S[i]);
		}
		for (int j = L[i] + 1, k = n / 2; j <= n + m; j++, k >>= 1) {
			for (int t = 0; t <= k; t++) {
				dp[j][t] = max(dp[j][t], max(dp[j - 1][2 * t], dp[j - 1][2 * t + 1]) + 1ll * t * C[j]);
			}
		}
	}
	ll R = 0;
	for (int i = 0; i <= n + m; i++) {
		R = max(R, dp[i][1]);
	}
	printf("%lld\n", R);
	return 0;
}
