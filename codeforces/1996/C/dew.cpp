#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long int ll;
typedef pair<int, int> pii;
 
#define F first
#define S second
#define lc id << 1
#define rc lc | 1
 
constexpr int N = 2e5 + 10, MOD = 1e9 + 7;
int cntA[30][N], cntB[30][N];

int main() {
    int q;
    for (scanf("%d", &q); q--;) {
        int n, k;
        scanf("%d%d", &n, &k);
        string a, b;
        cin >> a >> b;
        for (int i = 1; i <= n; i++) {
            int cA = a[i - 1] - 'a', cB = b[i - 1] - 'a';
            for (int j = 0; j < 30; j++) cntA[j][i] = cntA[j][i - 1];
            cntA[cA][i]++;
            for (int j = 0; j < 30; j++) cntB[j][i] = cntB[j][i - 1];
            cntB[cB][i]++;
        }
        for (int i = 1; i <= k; i++) {
            int l, r; scanf("%d%d", &l, &r);
            int sum = 0;
            for (int j = 0; j < 30; j++) {
                sum += abs((cntA[j][r] - cntA[j][l - 1]) - (cntB[j][r] - cntB[j][l - 1]));
            }
            printf("%d\n", sum / 2);
        }
    }
    return 0;
}
