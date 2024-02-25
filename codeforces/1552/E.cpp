/* I do it for the glory */
#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
 
#define SZ(x) (int) x.size()
#define F first
#define S second

const int N = 100 + 10, MOD = 1e9 + 7;
int n, k, A[N * N], M[N], lst[N];
vector<pii> ret;

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n * k; i++) 
        scanf("%d", &A[i]);
    for (int j = 0; j < n;) {
        memset(lst, 0, sizeof lst);
        for (int i = 1; i <= n * k; i++) {
            if (M[A[i]]) continue;
            if (lst[A[i]]) {
                ret.push_back({lst[A[i]], i}), M[A[i]] = 1, j++;
                memset(lst, 0, sizeof lst);
            } else lst[A[i]] = i;
        }
    }
    sort(begin(ret), end(ret), [&] (pii a, pii b) { return A[a.F] < A[b.F]; });
    for (pii &x : ret) printf("%d %d\n", x.F, x.S);
    return 0;
}

