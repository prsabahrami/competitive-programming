/* I do it for the glory */
#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
 
#define SZ(x)                       (int) x.size()
#define F                           first
#define S                           second

const int N = 1e6 + 10, MOD = 1e9 + 7;
int A[N], R[N], n, t;

int check(int l, int r) {
    for (int i = l; i <= r; i++) 
        for (int j = i + 1; j <= r; j++)    
            for (int k = j + 1; k <= r; k++) {
                if (A[i] >= A[j] && A[j] >= A[k]) return 0;
                if (A[i] <= A[j] && A[j] <= A[k]) return 0;
            }
    return 1;
}

int main() {
    scanf("%d", &t);
    for (; t; t--) {
        scanf("%d", &n); ll ret = 0;
        for (int i = 1; i <= n; i++) 
            scanf("%d", &A[i]);
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n + 1; j++) {
                if (!check(i, j) || j > n) { ret += j - i; break; }
            }
        }
        printf("%lld\n", ret);
    }
    return 0;
}

