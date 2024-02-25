#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;
 
#define SZ(x)                       (int) x.size()
#define F                           first
#define S                           second

const ll N = 1e6 + 10, MOD = 1e9 + 7;
ll pw[N], base = 737; int n, ptr = 0;
string A, S[N]; char C[N]; vector<ll> hsh[N], H;

ll get(ll l, ll r) {
	assert(r < SZ(H));
	return (H[r] - H[l - 1] * pw[r - l + 1] % MOD + MOD) % MOD;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		cin >> S[i];
	}
	pw[0] = 1;
	for (int i = 1; i < N; i++) {
		pw[i] = pw[i - 1] * base % MOD;
	}
	for (int i = 1; i <= n; i++) {
		hsh[i].push_back(0);
		for (int j = 0; j < SZ(S[i]); j++) {
			hsh[i].push_back((hsh[i].back() * base + S[i][j]) % MOD);
		}
		assert(SZ(hsh[i]) == SZ(S[i]) + 1);
	}
	A = S[1]; H = hsh[1];
	for (int i = 2; i <= n; i++) {
		int f = 0;
		for (int j = max(1, SZ(A) - SZ(S[i]) + 1); j <= SZ(A); j++) {
			if (get(j, SZ(A)) == hsh[i][SZ(A) - j + 1]) {
				for (int k = SZ(A) - j + 2; k <= SZ(S[i]); k++) {
					A += S[i][k - 1];
					H.push_back((H.back() * base + S[i][k - 1]) % MOD);
				}
				f = 1;
				break;
			}
		} 
		if (!f) {
			for (int j = 1; j <= SZ(S[i]); j++) {
				H.push_back((H.back() * base + S[i][j - 1]) % MOD);
				A += S[i][j - 1];
			}
		}
	}
	for (char c : A) printf("%c", c);
    return 0;
}

