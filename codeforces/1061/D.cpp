#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;
 
#define SZ(x)                       (ll) x.size()
#define F                           first
#define S                           second

const ll N = 1e5 + 10, MOD = 1e9 + 7;
ll L[N], R[N], X, Y; int n, id[N];
multiset<pll> st;

int main() {
	scanf("%d%lld%lld", &n, &X, &Y);
	for (int i = 1; i <= n; i++) scanf("%lld%lld", &L[i], &R[i]), id[i] = i;
	sort(id + 1, id + n + 1, [&](int x, int y) {
		//if (L[x] == L[y]) return R[x] > R[y];
		return L[x] < L[y];
	});
	for (int i = 1; i <= n; i++) {
		auto it = st.lower_bound({L[id[i]], -1});
		if (it == st.begin() || (-(--it)->F + L[id[i]]) * Y >= X) st.insert({R[id[i]], L[id[i]]});
		else {
			pll T =  *it;
			st.erase(it);
			st.insert({R[id[i]], T.S});
		}
	}
	ll ans = SZ(st) * X % MOD;
	for (auto x : st) ans = (ans + Y * (x.F - x.S) % MOD) % MOD;
	//for (auto x : st) printf("%lld %lld\n", x.S, x.F);
	printf("%lld\n", ans);
    return 0;
}

