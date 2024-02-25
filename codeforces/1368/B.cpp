#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
 
#define SZ(x)                       (int) x.size()
#define F                           first
#define S                           second

const int N = 1e6 + 10, MOD = 1e9 + 7;
ll k, b, A[11], mn = MOD;
char S[] = {'c', 'o', 'd', 'e', 'f', 'o', 'r', 'c', 'e', 's'};

int main() {
	scanf("%lld", &k);
	if (k == 1) {
		for (int i = 0; i < 10; i++) cout << S[i];
		return 0;
	}
	for (int i = 0; i < 10; i++) A[i] = 1;
	int ptr = 0;
	while (1) {
		ll mul = 1;
		for (int i = 0; i < 10; i++) mul *= A[i];
		if (mul >= k) break;
		A[ptr++]++;
		if (ptr == 10) ptr = 0;
	}
	for (int i = 0; i < 10; i++) {
		cout << string(A[i], S[i]);
	}
	return 0;
}
