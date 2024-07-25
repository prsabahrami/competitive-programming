#include <bits/stdc++.h>
#pragma GCC optimize("O3")
 
using namespace std;
 
typedef long long int ll;
typedef pair<int, int> pii;
 
#define F first
#define S second
#define lc id << 1
#define rc lc | 1
 
constexpr int N = 2e6 + 15, MOD = 1e9 + 7;
constexpr int MAXP = 45000, PN = 4675;
constexpr auto primes = []() constexpr {
    int ptr = 0;
    array<int, PN> primes{};
    array<bool, MAXP> is_prime{};
    for (int i = 2; i < MAXP; i++) {
        if (!is_prime[i]) primes[ptr++] = i;
        for (int j = 0; j < ptr && i * primes[j] < MAXP; j++) {
            is_prime[i * primes[j]] = true;
            if (i % primes[j] == 0) break;
        }
    }
    return primes;
}();

int A[N], n, k,  q, P[N], sz[N], lst[N >> 1]; vector<int> PD[N >> 1];

int find(int x) {
    return P[x] == -1 ? x : P[x] = find(P[x]);
}

void merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return;
    if (sz[x] < sz[y]) swap(x, y);
    P[y] = x, sz[x] += sz[y];
}

int main() {
    memset(lst, -1, sizeof(lst));
    for (int p : primes) {
        for (int j = p; j < N >> 1; j += p) {
            PD[j].push_back(p);
        }
    }
    for (int i = 2; i < N >> 1; i++) {
        int tmp = i;
        for (int p : PD[i]) {
            while (tmp % p == 0) tmp /= p;
        }
        if (tmp != 1) PD[i].push_back(tmp);
    }
    for (scanf("%d", &q); q--;) {
        ll ans = 0;
        scanf("%d%d", &n, &k);
        for (int i = n; i < 2 * n; i++) {
            scanf("%d", A + i);
            if (A[i] == 1) {
                ans += 2 * n - i - 1;
            }
            P[i] = -1, sz[i] = 1;
        }
        for (int i = 1; i < n; i++) {
            A[i] = A[i + n];
            if (A[i] == 1) {
                ans += i - 1;
            }
            P[i] = -1, sz[i] = 1;
        }
        for (int i = 1; i < 2 * n; i++) {
            for (int p : PD[A[i]]) {
                if (lst[p] != -1 && i - lst[p] <= k) merge(lst[p], i);
                lst[p] = i;
            }
        }
        for (int i = 1; i < 2 * n; i++) {
            if (find(i) == i) ans++;
        }
        for (int i = 1; i < 2 * n; i++) {
            for (int p : PD[A[i]]) {
                lst[p] = -1;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
