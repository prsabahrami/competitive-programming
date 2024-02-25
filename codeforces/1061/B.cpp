#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;
 
#define SZ(x)                       (ll) x.size()
#define F                           first
#define S                           second

const ll N = 1e6 + 10;
int n, m; ll A[N], s;

int main() {
	scanf("%d%d", &n, &m);
	if (n == 1) return !printf("0\n");
	for (int i = 1; i <= n; i++) scanf("%lld", &A[i]), s += A[i];
	sort(A + 1, A + n + 1); int t = 1;
	for (int i = 1; i <= n; i++) if (t <= A[i]) t++;
	printf("%lld\n", s - (n + *max_element(A, A + N) - t) - 1);
    return 0;
}

