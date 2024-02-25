#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;
 
#define SZ(x)                       (ll) x.size()
#define F                           first
#define S                           second

const ll N = 1e6 + 10;
int t, n, q;
string A;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &q);
		cin >> A; A = '#' + A;
		while (q--) {
			int l, r, f = 0; scanf("%d%d", &l, &r); 
			for (int i = r + 1; i <= n; i++) if (A[i] == A[r]) f = 1;
			for (int i = 1; i < l; i++) if (A[l] == A[i]) f = 1;
			if (f) printf("YES\n");
			else printf("NO\n");
		}
	}
    return 0;
}

