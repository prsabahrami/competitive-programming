#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;
 
#define SZ(x)                       (ll) x.size()
#define F                           first
#define S                           second

const ll N = 1e6 + 10, MOD = 1e9 + 7;
vector<int> D[N];
int n, A[N], dp[N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
	for (int i = 1; i < N; i++) {
		for (int j = i; j < N; j += i) D[j].push_back(i);
		reverse(D[i].begin(), D[i].end());
	}
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int d : D[A[i]]) {
			dp[d] = (dp[d] + dp[d - 1]) % MOD;
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = (ans + dp[i]) % MOD;
	}
	printf("%d\n", ans);
    return 0;
}

