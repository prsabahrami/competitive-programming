#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;
 
#define SZ(x)                       (int) x.size()
#define F                           first
#define S                           second

const ll N = 2e6 + 10, MOD[] = {(int) 1e9 + 7, (int) 1e9 + 9};
int base[] = {39, 737}, n, k, g, hsh[2][N], pw[2][N]; set<pair<int, int>> st;
map<pair<int, int>, int> mp;
char C[N]; string S[N];

pair<int, int> get(int l, int r) {
	int h[] = {0, 0};
	for (int i = 0; i < 2; i++) {
		h[i] = (1l * hsh[i][r] - 1ll * hsh[i][l - 1] * pw[i][r - l + 1] % MOD[i] + MOD[i]) % MOD[i];
	}
	return {h[0], h[1]};
}

int main() {
	pw[0][0] = pw[1][0] = 1;
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < 2; j++) {
			pw[j][i] = 1ll * pw[j][i - 1] * base[j] % MOD[j];
		}
	}
	scanf("%d%d%s", &n, &k, C);
	S[0] = C; scanf("%d", &g); S[0] = S[0] + S[0].substr(0, k - 1);
	for (int i = 1; i <= g; i++) {
		scanf("%s", C); S[i] = C;
		int h[] = {0, 0};
		for (int j = 0; j < 2; j++) {
			for (char c : S[i]) {
				h[j] = (1ll * h[j] * base[j] + c - 'a' + 1) % MOD[j];
			} 
		}
		mp[{h[0], h[1]}] = i;
	}
	for (int i = 1; i <= SZ(S[0]); i++) {
		for (int j = 0; j < 2; j++) {
			hsh[j][i] = (1ll * hsh[j][i - 1] * base[j] + S[0][i - 1] - 'a' + 1) % MOD[j];
		}
	}
	for (int i = 0; i < k; i++) {
		st.clear();
		for (int j = 0; j < n; j++) {
			pair<int, int> x = get(i + j * k + 1, i + (j + 1) * k);
			if (mp.find(x) != mp.end()) st.insert(x);
		}
		if (SZ(st) != n) continue; 
		printf("YES\n");
		for (int j = 0; j < n; j++) {
			printf("%d ", mp[get(i + j * k + 1, i + (j + 1) * k)]);
		}
		return !printf("\n");
	}
	printf("NO\n");
    return 0;
}

