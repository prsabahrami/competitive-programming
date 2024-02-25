#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;
 
#define SZ(x)                       (ll) x.size()
#define F                           first
#define S                           second

const ll N = 2e3 + 10;
int dpl[N][N], dpr[N][N], n, m, ans = 0, k;
pair<int, int> Q[N];

int eshterak(int l1, int r1, int l2, int r2) {
	return max(0, min(r1, r2) - max(l1, l2) + 1);
}
int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &Q[i].F, &Q[i].S);
	}
	sort(Q + 1, Q + m + 1, [&](pair<int, int> x, pair<int, int> y) {
		return x.F + x.S < y.F + y.S;
	});
	for (int i = k; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dpl[i][j] = dpl[i][j - 1] + eshterak(i - k + 1, i, Q[j].F, Q[j].S);
		}
		for (int j = m; j; j--) {
			dpr[i][j] = dpr[i][j + 1] + eshterak(i - k + 1, i, Q[j].F, Q[j].S);
		}
		ans = max(ans, dpl[i][m]);
		ans = max(ans, dpr[i][1]);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			int l = 1, r = m + 1; int midi = i + i - k + 1, nemidi = j + j - k + 1;
			while (r - l > 1) {
				int mid = (l + r) >> 1;
				if (abs(Q[mid].F + Q[mid].S - midi) < abs(Q[mid].F + Q[mid].S - nemidi)) l = mid;
				else r = mid;
			}
			ans = max(ans, dpl[i][l] + dpr[j][r]);
		}
	}
	printf("%d\n", ans);
    return 0;
}

