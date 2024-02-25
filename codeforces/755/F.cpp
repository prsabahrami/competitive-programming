#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
 
#define SZ(x)                       (int) x.size()
#define F                           first
#define S                           second

const int N = 1e6 + 10;
int P[N], M[N], C[N], n, k, t[2];
bitset<N> dp;

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%d", &P[i]);
    for (int i = 1; i <= n; i++) {
        if (!M[i]) {
            int l = 0;
            for (int j = i; !M[j]; j = P[j]) l++, M[j] = 1;
            t[0] += l / 2, t[1] += (l & 1);
            C[l]++;
        }
    }
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        while (C[i] > 2) {
            C[i] -= 2, C[i + i]++;
        }
        if (C[i]) 
            dp |= (dp << i), C[i]--;
        if (C[i]) 
            dp |= (dp << i), C[i]--;
    }
    int A1 = k + !dp[k];
    int A2 = min(t[0], k) * 2 + max(0, min(t[1], k - t[0]));
    printf("%d %d\n", A1, A2);
    return 0;
}
