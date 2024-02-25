#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
 
#define SZ(x)                       (int) x.size()
#define F                           first
#define S                           second

const int N = 1e6 + 10, MOD = 1e9 + 7;
int P[N], n, m; char S[N], C[N];

int check(int x) {
	string T = S;
	for (int i = 1; i <= x; i++) {
		T[P[i] - 1] = '.';
	}
	int ptr = 0;
	for (int i = 0; i < m; i++) {
		while (ptr < SZ(T) && T[ptr] != C[i]) ptr++;
		if (C[i] != T[ptr]) return 0;
		ptr++;
	}
	return 1;
}

int main() {
	scanf("%s%s", S, C); 
	n = strlen(S), m = strlen(C);
	for (int i = 1; i <= n; i++) scanf("%d", &P[i]);
	int l = 0, r = n + 1;
	while (r - l > 1) {
		int mid = (l + r) >> 1;
		if (check(mid)) l = mid;
		else r = mid;
	}
	printf("%d\n", l);
    return 0;
}

