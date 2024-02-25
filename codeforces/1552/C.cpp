/* I do it for the glory */
#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
 
#define SZ(x) (int) x.size()
#define F first
#define S second

const int N = 200 + 10, MOD = 1e9 + 7;
int M[N], n, k;

int main() {
    int t; 
    for (scanf("%d", &t); t; t--) {
        scanf("%d%d", &n, &k);
        fill(M, M + 3 * n + 1, -1); vector<pii> vec;
        for (int i = 1; i <= k; i++) {
            int u, v; scanf("%d%d", &u, &v); u--, v--;
            vec.push_back({u, v});
            M[u] = v, M[v] = u;
        }
        int ret = 0, c = 0;
        for (int i = 0; i < 2 * n; i++) if (!~M[i]) c++;
        c /= 2;
        ret = (c - 1) * c / 2;
        for (int i = 0; i < k; i++) {
            int u = vec[i].F, v = vec[i].S;
            int l = 0;
            for (int j = (u + 1) % (2 * n); j != v; j = (j + 1) % (2 * n)) 
                l += !~M[j];
            int r = 0;
            for (int j = (v + 1) % (2 * n); j != u; j = (j + 1) % (2 * n)) 
                r += !~M[j];
            ret += min(l, r);
        }
        for (int i = 0; i < k; i++) {
            for (int j = i + 1; j < k; j++) {
                int u1 = vec[i].F, v1 = vec[i].S;
                int u2 = vec[j].F, v2 = vec[j].S;
                int cnt = 0;
                for (int l = (u1 + 1) % (2 * n); l != v1; l = (l + 1) % (2 * n))
                    if (l == v2 || l == u2) cnt++;
                ret += (cnt == 1);
            }
        }
        printf("%d\n", ret);
    }
    return 0;
}

