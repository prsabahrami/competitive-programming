#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
 
#define SZ(x)                       (int) x.size()
#define F                           first
#define S                           second

const int N = 1e6 + 10, MOD = 1e9 + 7;
int q, n, k, X[N], Y[N];

int main() {
	scanf("%d", &q);
	while (q--) {
		scanf("%d%d", &n, &k);
		for (int i = 1; i <= n; i++) scanf("%d%d", &X[i], &Y[i]);
		int g = -1;
		for (int i = 1; i <= n; i++) {
			int f = 1;
			for (int j = 1; j <= n; j++) {
				if (abs(X[i] - X[j]) + abs(Y[i] - Y[j]) > k) f = 0;
			}
			if (f) g = i;
		}
		if (g != -1) printf("1\n");
		else printf("-1\n");
	}
	return 0;
}
