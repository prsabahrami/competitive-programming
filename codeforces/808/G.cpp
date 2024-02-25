#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;
 
#define SZ(x)                       (ll) x.size()
#define F                           first
#define S                           second

const ll N = 1e7 + 10;
int dp[2][N], F[N], n, m, k;
char S[N], T[N];

int check(int l, int r) {
	int tl = l;
	for (; l <= r; l++) if (S[l] != '?' && S[l] != T[l - tl]) return 0;
	return 1;
}

int main() {
	scanf("%s\n%s", S, T);
	n = strlen(S), m = strlen(T);
	F[0] = F[1] = 0;
	for (int i = 1; i < m; i++){
  		while (k && T[k] != T[i]) k = F[k];
  		if (T[k] == T[i]) k++;
  		F[i + 1] = k;
	}
	for (int i = n - m; i >= 0; i--) {
		if (!check(i, i + m - 1)) {
			dp[1][i] = dp[1][i + 1];
			continue;
		}
		dp[1][i] = dp[1][i + 1]; dp[0][i] = dp[1][i + m] + 1;
		for (int j = F[m]; j; j = F[j]) {
			dp[0][i] = max(dp[0][i], dp[0][i + m - j] + 1);
		}
		dp[1][i] = max(dp[1][i], dp[0][i]);
	}
	printf("%d\n", dp[1][0]);
    return 0;
}

