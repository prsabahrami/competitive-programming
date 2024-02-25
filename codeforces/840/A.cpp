#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
 
#define SZ(x)                       (int) x.size()
#define F                           first
#define S                           second

const int N = 2e5 + 10, MOD = 1e9 + 7;
int A[N], P[N], R[N] ,n; pii B[N];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
    }
    sort(A + 1, A + n + 1, greater<int>());
    for (int i = 1; i <= n; i++) scanf("%d", &B[i].F), B[i].S = i;
    sort(B + 1, B + n + 1);
    for (int i = 1; i <= n; i++) {
        R[B[i].S] = A[i];
    }
    for (int i = 1; i <= n; i++) printf("%d ", R[i]);
    printf("\n");
    return 0;
}
