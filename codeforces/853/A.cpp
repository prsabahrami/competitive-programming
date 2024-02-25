#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
 
#define SZ(x)                       (int) x.size()
#define F                           first
#define S                           second

const int N = 1e6 + 10, MOD = 1e9 + 7;
int n, k, C[N], A[N]; ll res = 0;
set<pii, greater<pii>> st; set<int> ts;

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%d", &C[i]), st.insert({C[i], i});
    for (int i = k + 1; i <= n + k; i++) ts.insert(i);
    while (SZ(st)) {
        int id = st.begin()->S;
        st.erase(st.begin());
        auto it = ts.lower_bound(id);
        auto it2 = it;
        if (it2 != ts.begin()) it2--;
        if (id - *it2 > *it - id) {
            A[id] = *it;
            ts.erase(it);
        } else {
            A[id] = *it2;
            ts.erase(it2);
        }
        res += 1ll * abs(A[id] - id) * C[id];
    }
    printf("%lld\n", res);
    for (int i = 1; i <= n; i++) printf("%d ", A[i]);
    printf("\n");
    return 0;
}
