#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
 
#define SZ(x)                       (int) x.size()
#define F                           first
#define S                           second

const int N = 1e5 + 10, MOD = 1e9 + 7;
int A[N], dp[2][N], n; ll R = 0, tot = 0;
vector<int> adj[N];

void DFS(int v, int b, int p = -1) {
	int t = bool(A[v] & (1 << b)), sum1 = 0, sum0 = 0;
	dp[t][v]++;
	for (int u : adj[v]) {
		if (u != p) {
			DFS(u, b, v);
            sum0 += dp[0][u];
            sum1 += dp[1][u];
			for (int i = 0; i < 2; i++) dp[i][v] += dp[t ^ i][u];
		}
	}
	for (int u : adj[v]) {
        if (u != p) {
            sum1 -= dp[1][u], sum0 -= dp[0][u];
            if (t) tot += 1ll * dp[0][u] * sum0 + 1ll * dp[1][u] * sum1;
            else tot += 1ll * dp[1][u] * sum0 + 1ll * dp[0][u] * sum1;
            sum1 += dp[1][u], sum0 += dp[0][u];
        }
    }
    tot += 2 * dp[1][v];
}

ll solve(int x) {
	tot = 0;
	fill(dp[0], dp[0] + N, 0);
	fill(dp[1], dp[1] + N, 0);
	DFS(1, x);
    return tot;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
	for (int i = 1; i < n; i++) {
		int u, v; scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 0; i <= 21; i++) {
		R += 1ll * (1 << i) * solve(i);
	}
    printf("%lld\n", R >> 1);
	return 0;
}

