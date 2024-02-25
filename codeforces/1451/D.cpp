#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;
 
#define SZ(x)                       (ll) x.size()
#define F                           first
#define S                           second

const ll N = 1e6 + 10;
ll t, k, d, y;

ll check(ll x) {
	return (x + k) * (x + k) + y * y <= d * d;
}

int main() {
	scanf("%lld", &t);
	while (t--) {
		int f = 0; scanf("%lld%lld", &d, &k); y = d;
		for (ll i = 0; i <= d; i += k) {
			for (; i * i + y * y > d * d; y--);
			y -= y % k;
			if (check(i) || (((i + y) / k) & 1)) continue;
			ll tx = i, ty = y;
			if (tx < ty) swap(tx, ty);
			if ((tx - ty) / k <= 2) f = 1;
		}
		if (f) printf("Utkarsh\n");
		else printf("Ashish\n");
	}
    return 0;
}