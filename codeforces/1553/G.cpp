/* I do it for the glory */
#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
 
#define SZ(x) (int) x.size()
#define F first
#define S second

const int N = 2e5 + 5, M = 1e6 + 5, MOD = 1e9 + 7;
int n, q, A[N], rt[M], bp[M]; map<pii, int> mp;

int Find(int v) { return !rt[v] ? v : rt[v] = Find(rt[v]); }

void Union(int u, int v) {
    u = Find(u), v = Find(v);
    if (u == v) return;
    rt[u] = v;
}

int main() {
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++) 
        scanf("%d", &A[i]);
    for (int i = 2; i < M; i++) {
        if (bp[i]) continue;
        for (int j = i; j < M; j += i) bp[j] = i;
    }
    for (int i = 1; i <= n; i++) {
        int lst = -1;
        for (int x = A[i]; x > 1; x /= bp[x]) 
            if (bp[x] != bp[x / bp[x]]) {
                if (~lst) Union(bp[x], lst);
                lst = bp[x];
            }
    }
    for (int i = 1; i <= n; i++) {
        int p = Find(bp[A[i]]);
        vector<int> P;
        for (int x = A[i] + 1; x > 1; x /= bp[x]) 
            if (bp[x] != bp[x / bp[x]]) P.push_back(bp[x]);
        for (int &x : P) {
            mp[{Find(x), p}] = mp[{p, Find(x)}] = 1;
            for (int &y : P) mp[{Find(x), Find(y)}] = 1;
        }
    }
    for (; q; q--) {
        int u, v; scanf("%d%d", &u, &v);
        int x = A[u], y = A[v];
        if (Find(bp[x]) == Find(bp[y])) printf("0\n");
        else if (mp.count({Find(bp[x]), Find(bp[y])})) printf("1\n");
        else printf("2\n");
    }
    return 0;
}

