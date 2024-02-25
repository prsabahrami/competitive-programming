/* I do it for the glory */
#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
 
#define SZ(x) (int) x.size()
#define F first
#define S second

const int N = 5e4 + 10, MOD = 1e9 + 7;
int t, n, A[5][N], ord[N], C[N];

int main() {
    for (scanf("%d", &t); t; t--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) 
            for (int j = 0; j < 5; j++) 
                scanf("%d", &A[j][i]);
        int opt = 1;
        for (int i = 2; i <= n; i++) {
            int c = 0;
            for (int j = 0; j < 5; j++) 
                if (A[j][opt] < A[j][i]) c++;
            if (c >= 3) continue;
            opt = i;
        }
        for (int i = 1; i <= n && ~opt; i++) {
            if (i == opt) continue;
            int c = 0;
            for (int j = 0; j < 5; j++) {
                c += (A[j][opt] < A[j][i]);
            }
            if (c < 3) opt = -1;
        }
        if (~opt) printf("%d\n", opt);
        else printf("-1\n");
    }
    return 0;
}

