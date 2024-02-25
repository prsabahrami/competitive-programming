#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;
 
#define SZ(x)                       (ll) x.size()
#define F                           first
#define S                           second

const ll N = 1e6 + 10;
int t;

int main() {
	scanf("%d",&t);
	while (t--) {
		int x, y; scanf("%d%d", &x, &y);
		printf("%d\n", max(x, y) * 2 - 1 + (x == y));
	}
    return 0;
}

