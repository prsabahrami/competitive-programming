#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
 
#define SZ(x)                       (int) x.size()
#define F                           first
#define S                           second

const int N = 1e6 + 10, MOD = 1e9 + 7;
ll A[N], n, S = 0, C[30];

int main() {
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++) scanf("%lld", &A[i]);
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 28; j++) {
			if (A[i] & (1 << j)) C[j]++;
		}
	}
	for (int i = 1; i <= n; i++) {
		ll k = 0;
		for (int j = 0; j < 28; j++) {
			if (C[j]) k += (1 << j), C[j]--;
		}
		S += k * k;
	}
	printf("%lld\n", S);
	return 0;
}
