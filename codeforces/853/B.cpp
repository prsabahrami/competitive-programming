#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
 
#define SZ(x)                       (int) x.size()
#define F                           first
#define S                           second

const int N = 1e5 + 10;
ll ML[N], MR[N], lst[N], C = 1e18; 
int n, m, k;
vector<pair<int, pii>> in, out;

int main() {
    fill(lst, lst + N, 1e12);
    fill(ML, ML + N, 1e12);
    fill(MR, MR + N, 1e12);
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= m; i++) {
        int d, t, f, c; scanf("%d%d%d%d", &d, &f, &t, &c);
        if (!t) in.push_back({d, {c, f}});
        else out.push_back({d, {c, t}});
    }
    C = 1e12 * n;
    sort(in.begin(), in.end());
    sort(out.begin(), out.end());
    for (int i = 0; i < SZ(in); i++) {
         int a = in[i].S.S, c = in[i].S.F;
         if (lst[a] > c) {
            C -= lst[a];
            lst[a] = c;
            C += lst[a];
         }
         ML[i] = C;
    }
    C = 1e12 * n;
    fill(lst, lst + N, 1e12);
    for (int i = SZ(out) - 1; ~i; i--) {
        int a = out[i].S.S, c = out[i].S.F;
        if (lst[a] > c) {
            C -= lst[a];
            lst[a] = c;
            C += lst[a];
        }
        MR[i] = C;
    }
    ll res = 1e18;
    for (int i = 0; i < SZ(in); i++) {
        int t = in[i].F;
        int pos = lower_bound(out.begin(), out.end(), make_pair(t + k + 1, pii(-1, -1))) - out.begin();
        res = min(res, ML[i] + MR[pos]);
    }
    if (res > 1e11) printf("-1\n");
    else printf("%lld\n", res);
    return 0;
}
