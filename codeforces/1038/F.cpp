/* I do it for the glory */
#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
 
#define SZ(x)                       (int) x.size()
#define F                           first
#define S                           second

const int N = 42, MOD = 1e9 + 7;
int M[N], n, m; ll dp[N], pw[N];
char S[N]; 

int main() {
    pw[0] = 1;
    for (int i = 1; i < N; i++) 
        pw[i] = pw[i - 1] * 2;
    scanf("%d", &n);
    scanf("%s", S);
    m = strlen(S);
    for (int i = 0; i < n; i++) {
        int f = 1;
        for (int j = 0; j < m; j++) {
            if (((i + j) % n) < m && S[j] != S[(i + j) % n]) f = 0;
        }
        M[i] = f;
    }
    dp[0] = 1; ll ret = 0;
    for (int i = 0; i < n; i++) {
        if (!M[i]) continue;
        if (i) {
            for (int j = 0; j < n; j++) {
                if (!M[j]) continue;
                if (((i + j) % n) < i) dp[i] -= dp[(i + j) % n] * pw[max(i - (i + j) % n - m, 0)];
            }
        }
        ret += dp[i] * (n - i) * pw[max(0, n - i - m)];
    }
    printf("%lld\n", ret);
    return 0;
}

