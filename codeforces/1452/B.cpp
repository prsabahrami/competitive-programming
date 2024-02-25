#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;
 
#define SZ(x)                       (ll) x.size()
#define F                           first
#define S                           second

const ll N = 1e6 + 10;
ll t, A[N];

int main() {
	scanf("%lld", &t);
	while (t--) {
		ll n, sum = 0; scanf("%lld", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%lld", &A[i]);
		} 
		sort(A + 1, A + n + 1);
		for (int i = 2; i < n; i++) sum += A[n] - A[i];
		if (A[1] <= sum) printf("%lld\n", sum - A[1]);
		else {
			printf("%lld\n", ((A[1] - sum + n - 2) / (n - 1)) * (n - 1) - A[1] + sum);
		}
	}
    return 0;
}

