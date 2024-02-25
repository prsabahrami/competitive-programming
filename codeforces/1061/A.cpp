#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;
 
#define SZ(x)                       (ll) x.size()
#define F                           first
#define S                           second

const ll N = 1e6 + 10;
ll s, n, t;

int main() {
	scanf("%lld%lld", &n, &s);
	printf("%lld\n", s / n + (s % n != 0));
    return 0;
}

