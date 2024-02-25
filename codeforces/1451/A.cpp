#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;
 
#define SZ(x)                       (ll) x.size()
#define F                           first
#define S                           second

const ll N = 1e6 + 10;
int n, t;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		if (n >= 4) printf("%d\n", 2 + (n & 1));
		else if (n == 3) printf("2\n");
		else if (n == 2) printf("1\n");
		else printf("0\n");
	}
    return 0;
}

