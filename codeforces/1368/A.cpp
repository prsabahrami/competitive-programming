#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
 
#define SZ(x)                       (int) x.size()
#define F                           first
#define S                           second

const int N = 1e6 + 10, MOD = 1e9 + 7;
int t, a, b, n;

int main() {
	for (scanf("%d", &t); t; t--) {
		scanf("%d%d%d", &a, &b, &n); int cnt = 0;
		while (max(a, b) <= n) {
			if (a < b) swap(a, b);
			b += a;
			cnt++;
		}
		printf("%d\n", cnt);
	}
	return 0;
}
