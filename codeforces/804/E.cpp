/* I do it for the glory */
#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
 
#define SZ(x)                       (int) x.size()
#define F                           first
#define S                           second

const int N = 1e3 + 10, MOD = 1e9 + 7;
int n; 

void solve(int i, int j, int k, int l, int m) {
    printf("%d %d\n", i, j);
    printf("%d %d\n", i, k);
    printf("%d %d\n", l, m);
    printf("%d %d\n", k, m);
    printf("%d %d\n", i, l);
    printf("%d %d\n", j, m);
    printf("%d %d\n", i, m);
    printf("%d %d\n", j, l);
    printf("%d %d\n", k, l);
    printf("%d %d\n", j, k);
}

int main() {
    scanf("%d", &n);
    if (n % 4 > 1) return !printf("NO\n");
    printf("YES\n");
    if (n < 2) return 0;
    if (n % 4 < 1) {
        for (int i = 0; i < n; i += 4) {
            printf("%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n", i + 1, i + 2, i + 3, i + 4, i + 2, i + 3, i + 1, i + 4, i + 1, i + 3, i + 2, i + 4);
        }
        for (int i = 0; i < n; i += 4) {
            for (int j = i + 4; j < n; j += 4) {
                printf("%d %d\n%d %d\n%d %d\n%d %d\n", i + 1, j + 1, i + 2, j + 2, i + 3, j + 3, i + 4, j + 4);
                printf("%d %d\n%d %d\n%d %d\n%d %d\n", i + 1, j + 2, i + 2, j + 1, i + 3, j + 4, i + 4, j + 3);
                printf("%d %d\n%d %d\n%d %d\n%d %d\n", i + 1, j + 3, i + 2, j + 4, i + 3, j + 1, i + 4, j + 2);
                printf("%d %d\n%d %d\n%d %d\n%d %d\n", i + 1, j + 4, i + 2, j + 3, i + 3, j + 2, i + 4, j + 1);
            }
        }
    } else {
        for (int i = 1; i <= n - 1; i += 4) 
            solve(i, i + 1, i + 2, i + 3, n);
        for (int i = 0; i < n - 1; i += 4) {
            for (int j = i + 4; j < n - 1; j += 4) {
                printf("%d %d\n%d %d\n%d %d\n%d %d\n", i + 1, j + 1, i + 2, j + 2, i + 3, j + 3, i + 4, j + 4);
                printf("%d %d\n%d %d\n%d %d\n%d %d\n", i + 1, j + 2, i + 2, j + 1, i + 3, j + 4, i + 4, j + 3);
                printf("%d %d\n%d %d\n%d %d\n%d %d\n", i + 1, j + 3, i + 2, j + 4, i + 3, j + 1, i + 4, j + 2);
                printf("%d %d\n%d %d\n%d %d\n%d %d\n", i + 1, j + 4, i + 2, j + 3, i + 3, j + 2, i + 4, j + 1);
            }
        }  
    }
    return 0;
}

