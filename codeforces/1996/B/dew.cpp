#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long int ll;
typedef pair<int, int> pii;
 
#define F first
#define S second
#define lc id << 1
#define rc lc | 1
 
constexpr int N = 1e3 + 10, MOD = 1e9 + 7;
char A[N][N];

int main() {
    int q;
    for (scanf("%d", &q); q--;) {
        int n, k;
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> A[i][j];
            }
        }
        for (int i = 1; i <= n; i += k) {
            for (int j = 1; j <= n; j += k) {
                printf("%c", A[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
