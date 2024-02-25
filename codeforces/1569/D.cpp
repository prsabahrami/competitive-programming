/* Just a drop of water in an endless sea */
#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
 
#define SZ(x) (int) x.size()
#define F first
#define S second

const int N = 1e6 + 10, MOD = 1e9 + 7;
int t, n, m, k, X[N], Y[N], F[N]; pii C[N];
vector<int> vec[N], cev[N];

ll C2(int x) { return 1ll * x * (x - 1) / 2; }

int main() {
    for (scanf("%d", &t); t; t--) {
        scanf("%d%d%d", &n, &m, &k);
        for (int i = 1; i <= n; i++) 
            scanf("%d", &X[i]);
        for (int i = 1; i <= m; i++) 
            scanf("%d", &Y[i]);
        for (int i = 1; i <= k; i++) {
            int x, y; scanf("%d%d", &x, &y);
            auto it = lower_bound(X + 1, X + n + 1, x);
            if (*it == x) F[i]++;
            it = lower_bound(Y + 1, Y + m + 1, y);
            if (*it == y) F[i] += 2;
            C[i] = {x, y};
        }
        vector<int> A, B;
        for (int i = 1; i <= k; i++) {
            if (F[i] < 2) A.push_back(i), cev[C[i].F].push_back(i);
            else if (F[i] < 3) B.push_back(i), vec[C[i].S].push_back(i);
        }
        for (int i = 1; i <= max(n, m); i++) {
            sort(begin(vec[Y[i]]), end(vec[Y[i]]), [&] (int x, int y) { return C[x].F < C[y].F; });
            sort(begin(cev[X[i]]), end(cev[X[i]]), [&] (int x, int y) { return C[x].S < C[y].S; });
        }
        sort(begin(A), end(A), [&] (int i, int j) { return C[i].S < C[j].S; });
        sort(begin(B), end(B), [&] (int i, int j) { return C[i].F < C[j].F; });
        ll ret = 0;
        for (int i = 1; i < n; i++) {
            int l = -1, r = SZ(B);
            for (; r - l > 1; ) {
                int md = (l + r) >> 1;
                if (C[B[md]].F > X[i]) r = md;
                else l = md;
            }
            int dn = r;
            l = 0, r = SZ(B);
            for (; r - l > 1; ) {
                int md = (l + r) >> 1;
                if (C[B[md]].F < X[i + 1]) l = md;
                else r = md;
            }
            ret += C2(l - dn + 1);
        }
        for (int i = 1; i < m; i++) {
            int l = -1, r = SZ(A);
            for (; r - l > 1; ) {
                int md = (l + r) >> 1;
                if (C[A[md]].S > Y[i]) r = md;
                else l = md;
            }
            int dn = r;
            l = 0, r = SZ(A);
            for (; r - l > 1; ) {
                int md = (l + r) >> 1;
                if (C[A[md]].S < Y[i + 1]) l = md;
                else r = md;
            }
            ret += C2(l - dn + 1);
        }
        for (int i = 1; i <= m; i++) {
            int c = 1;
            for (int j = 1; j <= SZ(vec[Y[i]]); j++) {
                if (j == SZ(vec[Y[i]])) { ret -= C2(c); break; }
                int id = vec[Y[i]][j], l = vec[Y[i]][j - 1];
                auto it = lower_bound(X + 1, X + n + 1, C[id].F);
                auto it2 = lower_bound(X + 1, X + n + 1, C[l].F);
                if (*it != *it2) ret -= C2(c), c = 1;
                else c++;
            }
        }
        for (int i = 1; i <= n; i++) {
            int c = 1;
            for (int j = 1; j <= SZ(cev[X[i]]); j++) {
                if (j == SZ(cev[X[i]])) { ret -= C2(c); break; }
                int id = cev[X[i]][j], l = cev[X[i]][j - 1];
                auto it = lower_bound(Y + 1, Y + m + 1, C[id].S);
                auto it2 = lower_bound(Y + 1, Y + m + 1, C[l].S);
                if (*it != *it2) ret -= C2(c), c = 1;
                else c++;
            }
        }
        printf("%lld\n", ret);
        for (int i = 1; i <= k; i++) 
            F[i] = 0;
        for (int i = 1; i <= max(n, m); i++) 
            vec[Y[i]] = cev[X[i]] = {};
    }
    return 0;
}

