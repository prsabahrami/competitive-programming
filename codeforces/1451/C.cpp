#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;
 
#define SZ(x)                       (ll) x.size()
#define F                           first
#define S                           second

const ll N = 1e6 + 10;
int t, n, k, cnt[2][30];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &k);
		fill(cnt[0], cnt[0] + 30, 0);
		fill(cnt[1], cnt[1] + 30, 0);
		for (int i = 1; i <= n; i++) {
			char c; cin >> c;
			cnt[0][c - 'a']++;
		}
		for (int i = 1; i <= n; i++) {
			char c; cin >> c;
			cnt[1][c - 'a']++;
		} int f = 1;
		for (int i = 0; i < 26; i++) {
			if (cnt[0][i] < cnt[1][i] || (cnt[0][i] - cnt[1][i]) % k > 0) f = 0;
			else cnt[0][i + 1] += cnt[0][i] - cnt[1][i];
		}
		if (f) printf("Yes\n");
		else printf("No\n");
	}
    return 0;
}

