#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;
 
#define SZ(x)                       (ll) x.size()
#define F                           first
#define S                           second

const ll N = (1 << 17) + 10;
int A[N], C[N], X[N], n;

void tekrary(int i, int j) {
	printf("AND %d %d\n", i, j);
	fflush(stdout);
	int x; scanf("%d", &x);
	A[1] = X[j] ^ x;
	for (int kk = 2; kk <= n; kk++) A[kk] = X[kk] ^ A[1];
	printf("! ");
	for (int k = 1; k <= n; k++) printf("%d ", A[k]);
	printf("\n");
	exit(0);
}

int main() {
	scanf("%d", &n);
	for (int i = 2; i <= n; i++) {
		printf("XOR %d %d\n", 1, i);
		fflush(stdout);
		int x; scanf("%d", &x);
		X[i] = x;
	}
	for (int i = 2; i <= n; i++) {
		if (X[i] == 0) tekrary(1, i);
		if (C[X[i]]) tekrary(C[X[i]], i);
		C[X[i]] = i;
	}
	int pos, pos2;
	for (int i = 2; i <= n; i++) {
		if (X[i] == 1) pos = i;
		if (X[i] == 2) pos2 = i; 
	}
	int x, y; 
	printf("AND %d %d\n", 1, pos);
	fflush(stdout);
	scanf("%d", &x);
	printf("AND %d %d\n", 1, pos2);
	fflush(stdout);
	scanf("%d", &y);
	if (y & 1) A[1] = x ^ 1;
	else A[1] = x;
	for (int kk = 2; kk <= n; kk++) A[kk] = X[kk] ^ A[1];
	printf("! ");
	for (int k = 1; k <= n; k++) printf("%d ", A[k]);
	printf("\n");
    return 0;
}

