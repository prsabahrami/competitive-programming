/* I do it for the glory */
#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
 
#define SZ(x)                       (int) x.size()
#define F                           first
#define S                           second

const int N = 3e5 + 10, MOD = 1e9 + 7;
struct obdWick {
    ll F[N];

    obdWick() { memset(F, 0, sizeof F); }

    void upd(int p, int x) { for (p++; p < N; p += p & -p) F[p] += x; }

    ll get(int p) { ll rt = 0; for (p++; p; p -= p & -p) rt += F[p]; return rt; }

    ll get(int l, int r) { 
        r = min(N - 2, r); return get(r) - get(l - 1); 
    }

} F[3];
int n, A[N]; ll ret;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        for (int j = 0; j < N; j += x) {
            ret += F[0].get(j, j + x - 1) - 1ll * j * F[1].get(j, j + x - 1);
        }
        ret += 1ll * x * (i - 1) - F[2].get(x);
        F[0].upd(x, x), F[1].upd(x, 1);
        for (int j = x; j < N; j += x) F[2].upd(j, x);
        printf("%lld ", ret);
    }
    return 0;
}

