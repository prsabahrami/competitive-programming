/* I do it for the glory */
#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
 
#define SZ(x) (int) x.size()
#define F first
#define S second

const int N = 1e6 + 10, MOD = 1e9 + 7;
ll A[N], n, gc[18][N], lg[N];

ll get(int l, int r) {
    int g = lg[r - l + 1];
    return __gcd(gc[g][l], gc[g][r - (1 << g) + 1]);
}

int check(int x) {
    if (x >= n) return 0;
    for (int i = 1; i + x <= n; i++) {
        if (get(i, i + x - 1) > 1) return 1;
    }
    return 0;
}

void Main() {
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &A[i]);
    }
    if (n < 2) { printf("1\n"); return; }
    for (int i = 1; i < n; i++) 
        gc[0][i] = A[i] = abs(A[i + 1] - A[i]);
    for (int j = 1; j < 18; j++) 
        for (int i = 1; i < n; i++) {
            if (i + (1 << j) <= n) 
                gc[j][i] = __gcd(gc[j - 1][i], gc[j - 1][i + (1 << (j - 1))]);
        }
    int ret = 1, pt = 1; ll g = 0;
    for (int i = 1; i < n; i++) {
        if (pt <= i) g = 0, pt = i;
        while (pt < n && abs(__gcd(g, A[pt])) != 1) { g = __gcd(g, A[pt]), pt++; }
        ret = max(ret, pt - i + 1);
        g = get(i + 1, pt - 1);
    }
    printf("%d\n", ret);
    for (int i = 0; i < 18; i++) 
        for (int j = 0; j <= n; j++)
            gc[i][j] = 0;
}

int main() {
    for (int i = 2; i < N; i++) 
        lg[i] = lg[i / 2] + 1;
    int t;
    scanf("%d", &t);
    for (; t; t--) {
        Main();
    }
    return 0;
}
