/* I do it for the glory */
#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
 
#define SZ(x)                       (int) x.size()
#define F                           first
#define S                           second

const int N = 2e5 + 10, K = 22;
int T, n, k, M[K][K], lg[N], C[K]; char S[N]; vector<int> pos[K];
ll dp[1 << K]; int pd[20][N + N];

int get(int l, int r) {
    if (r < l) return 0;
    int x = lg[r - l + 1];
    return pd[x][l] | pd[x][r - (1 << x) + 1];
}

int main() {
    for (int i = 2; i < N; i++)
        lg[i] = lg[i / 2] + 1;
    scanf("%d%d%d", &n, &k, &T);
    scanf("%s", S + 1);
    for (int i = 1; i <= n; i++) {
        pos[S[i] - 'A'].push_back(i);
        pd[0][i] = 1 << (S[i] - 'A');
    }
    for (int i = 1; i < 20; i++) 
        for (int j = 1; j <= n; j++) 
            if (j + (1 << i) <= n + 1) 
                pd[i][j] = pd[i - 1][j] | pd[i - 1][j + (1 << (i - 1))];
    for (int i = 0; i < k; i++)
        scanf("%d", &C[i]);
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            scanf("%d", &M[i][j]);
        }
    }
    for (int i = 0; i < k; i++) 
        for (int j = 0; j < k; j++) {
            if (i ^ j) {
                vector<int> vec;
                merge(pos[i].begin(), pos[i].end(), pos[j].begin(), pos[j].end(), back_inserter(vec));
                for (int p = 0; p + 1 < SZ(vec); p++) {
                    int a = vec[p], b = vec[p + 1];
                    if ((S[a] ^ S[b]) && S[a] - 'A' == i) {
                        int msk = get(a + 1, b - 1);
                        dp[msk] += M[i][j];
                        dp[msk ^ (1 << i)] -= M[i][j];
                        dp[msk ^ (1 << j)] -= M[i][j];
                        dp[msk ^ (1 << i) ^ (1 << j)] += M[i][j];
                    }
                }
            } else {
                for (int p = 0; p + 1 < SZ(pos[i]); p++) {
                    int msk = get(pos[i][p] + 1, pos[i][p + 1] - 1);
                    dp[msk] += M[i][j];
                    dp[msk ^ (1 << i)] -= M[i][j];
                }
            }
        }
    int ret = 0;
    for (int j = 0; j < k; j++) 
        for (int i = 0; i < 1 << k; i++) {
            if (i & (1 << j)) dp[i] += dp[i ^ (1 << j)];
    }
    for (int i = 0; i < (1 << k) - 1; i++) {
        int f = 0;
        for (int j = 0; j < k; j++) {
            if (!(i & (1 << j))) f |= (SZ(pos[j]) > 0);
        }
        for (int j = 0; j < k; j++) {
            if (i & (1 << j)) dp[i] += C[j], f &= (SZ(pos[j]) > 0);
        }
        if (f && dp[i] <= T) ret++;
    }
    printf("%d\n", ret);
    return 0;
}

