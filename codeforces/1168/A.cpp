#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
 
#define SZ(x)                       (int) x.size()
#define F                           first
#define S                           second

const int N = 1e6 + 10, MOD = 1e9 + 7;
int n, m, A[N], res;

int check(int x) {
    int M = 0;
    for (int i = 1; i <= n; i++) {
        if (A[i] + x < m) {
            if (A[i] + x < M) return 0;
            M = max(M, A[i]);
        } else {
            if (A[i] + x - m >= M) continue;
            M = max(M,  A[i]);
        }
    }
    return 1;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    int l = 0, r = m - 1;
    while (r - l > 1) {
        int mid = (l + r) >> 1;
        if (check(mid)) r = mid;
        else l = mid;
    }
    if (check(r - 1)) r--;
    printf("%d\n", r);
    return 0;
}
