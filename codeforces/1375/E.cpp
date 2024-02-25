#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;
 
#define SZ(x)                       (ll) x.size()
#define F                           first
#define S                           second

const ll N = 1e6 + 10;
int n, A[N]; vector<pair<int, int>> vec;

int cmp(pair<int, int> x, pair<int, int> y) {
	if (x.S != y.S) return x.S > y.S;
	if (A[x.F] != A[y.F]) return A[x.F] < A[y.F];
	return x.F < y.F;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &A[i]);
		for (int j = 1; j < i; j++) if (A[j] > A[i]) vec.push_back({j, i});
	}
	sort(vec.begin(), vec.end(), cmp);
	printf("%lld\n", SZ(vec));
	for (auto &i : vec) printf("%d %d\n", i.F, i.S);
    return 0;
}

