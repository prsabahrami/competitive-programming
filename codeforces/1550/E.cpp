/* I do it for the glory */
#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
 
#define SZ(x)                       (int) x.size()
#define F                           first
#define S                           second

const int N = 2e5 + 10, MOD = 1e9 + 7, K = 17;
vector<int> pos[K]; int n, k, lst[K], dp[1 << K]; char S[N];

int check(int x) {
    memset(lst, -1, sizeof lst);
    memset(dp, -1, sizeof dp);
    for (int i = 0; i < k; i++) 
        pos[i] = {};
    for (int i = 1; i < x; i++) 
        if (S[i] != '?') lst[S[i] - 'a'] = i;
    for (int i = x; i <= n; i++) {
        if (S[i] != '?') lst[S[i] - 'a'] = i;
        int y = -1, c = 0;
        for (int j = 0; j < k; j++) {
            if (lst[j] > i - x) y = j, c++;
        }
        if (c > 1) continue;
        if (c) pos[y].push_back(i);
        else { for (int j = 0; j < k; j++) pos[j].push_back(i); }
    }
    for (int i = 0; i < k; i++) 
        dp[1 << i] = SZ(pos[i]) ? pos[i].front() : -1;
    /*for (int i = 0; i < k; i++, printf("\n")) {
        printf("%d ", i);
        for (int j : pos[i]) printf("%d ", j);
    }*/ 
    for (int i = 1; i < 1 << k; i++) {
        if (__builtin_popcount(i) < 2) continue;
        for (int j = 0; j < k; j++) {
            if (i & (1 << j)) {
                int p = dp[i - (1 << j)];
                if (!~p) continue;
                else {
                    auto nx = lower_bound(pos[j].begin(), pos[j].end(), p + x);
                    if (nx != pos[j].end()) 
                        dp[i] = (~dp[i] ? min(dp[i], *nx) : *nx);
                }
            }
        }
    }
    return ~dp[(1 << k) - 1];
}

int main() {
    scanf("%d%d", &n, &k);
    scanf("%s", S + 1);
    int l = 0, r = n + 1;
    while (r - l > 1) {
        int md = (l + r) >> 1;
        if (check(md)) l = md;
        else r = md;
    }
    printf("%d\n", l);
    //check(5);
    return 0;
}

