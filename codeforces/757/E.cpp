#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
 
#define SZ(x)                       (int) x.size()
#define F                           first
#define S                           second

int Pow(int a, int b, int md, int res = 1) {
    for (; b; b >>= 1, a = 1ll * a * a % md) {
        if (b & 1) res = 1ll * res * a % md;
    }
    return res;
}

const int N = 2e6 + 10, MOD = 1e9 + 7;
vector<int> P[N];
int q, r, n, F[N], I[N];

int C(int x, int y) {
    if (!y || x == y) return 1;
    if (x < y) return 0;
    return 1ll * F[x] * I[y] % MOD * I[x - y] % MOD;
}

int main() {
    for (int i = 2; i < N; i++) {
        if (SZ(P[i])) continue;
        for (int j = i; j < N; j += i) {
            P[j].push_back(i);
        }
    }
    F[0] = 1; 
    for (int i = 1; i < N; i++) {
        F[i] = 1ll * i * F[i - 1] % MOD;
    }
    I[N - 1] = Pow(F[N - 1], MOD - 2, MOD);
    for (int i = N - 2; i >= 0; i--) {
        I[i] = 1ll * I[i + 1] * (i + 1) % MOD;
    }
    for (scanf("%d", &q); q; q--) {
        scanf("%d%d", &r, &n);
        int tot = 1;
        for (int p : P[n]) {
            int cnt = 0;
            while (n % p == 0) n /= p, cnt++;
            tot = 1ll * tot * (C(cnt + r, r) + C(cnt + r - 1, r)) % MOD;
        }
        printf("%d\n", tot);
    }
    return 0;
}
