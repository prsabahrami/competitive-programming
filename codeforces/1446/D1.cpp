/* I do it for the glory */
#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
 
#define SZ(x)                       (int) x.size()
#define F                           first
#define S                           second

const int N = 2e5 + 10, MOD = 1e9 + 7;
int A[N], ps[101][N], lst[101][2 * N], C[N], n;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &A[i]), C[A[i]]++;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 100; j++) ps[j][i] = ps[j][i - 1];
        ps[A[i]][i]++;
    }
    int mx = 0, ct = 0;
    for (int i = 1; i <= 100; i++) {
        if (C[i] < C[mx]) continue;
        if (C[i] > C[mx]) mx = i, ct = 1;
        else ct++;
    }
    if (ct > 1) return !printf("%d\n", n);
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= 100; j++) 
            if (j != mx) ps[j][i] = ps[mx][i] - ps[j][i];
    memset(lst, -1, sizeof lst); int ret = 0;
    for (int i = 1; i <= 100; i++)
        lst[i][n] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 100; j++) {
            if (j == mx) continue;
            if (~lst[j][ps[j][i] + n]) 
                ret = max(ret, i - lst[j][ps[j][i] + n]);
            else lst[j][ps[j][i] + n] = i;
        }
    }
    printf("%d\n", ret);
    return 0;
}

