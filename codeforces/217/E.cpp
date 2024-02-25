/* I do it for the glory */
#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
 
#define SZ(x) (int) x.size()
#define F first
#define S second

const int N = 3e6 + 10, MOD = 1e9 + 7, M = 5e3 + 10;
int F[N], rt[N], k, n, q; pii Q[M]; char S[N], ans[N];

void upd(int p, int x) { for (; p <= k; p += p & -p) F[p] += x; }

int get(int p) { int ret = 0; for (; p; p -= p & -p) ret += F[p]; return ret; }

int BS(int p) {
    int sum = 0, l = 0;
    for (int i = 23; ~i; i--) {
        l ^= 1 << i;
        if (l > k || sum + F[l] >= p) l ^= (1 << i);
        else sum += F[l];
    }
    return l + 1;
}

int main() {
    scanf("%s%d", S + 1, &k); n = strlen(S + 1);
    for (int i = 1; i <= k; i++) 
        upd(i, 1);
    scanf("%d", &q);
    for (int i = 1, l, r; i <= q; i++) {
        scanf("%d%d", &l, &r);
        Q[i] = {l, r};
    }
    for (int _ = q; _; _--) {
        int l = Q[_].F, r = Q[_].S;
        if (r >= k) continue;
        int p = l + 1, y = get(k); vector<int> vec;
        for (int i = r + 1; i <= min(y, 2 * r - l + 1); i++, p += 2) {
            if (p > r) p = l;
            int x = BS(i); vec.push_back(x);
            rt[x] = BS(p);
        }
        for (int &x : vec) upd(x, -1);
    }
    for (int i = 1; i <= k; i++) {
        if (!rt[i]) ans[i] = S[get(i)];
        else ans[i] = ans[rt[i]];
        printf("%c", ans[i]);
    }
    printf("\n");
    return 0;
}

