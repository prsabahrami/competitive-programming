/* I do it for the glory */
#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
 
#define SZ(x)                       (int) x.size()
#define F                           first
#define S                           second

const int N = 1e6 + 10, MOD = 1e9 + 7;
char S[N]; int n, t, a, b;

int main() {
    for (scanf("%d", &t); t; t--) {
        scanf("%d%d%d", &n, &a, &b);
        scanf("%s", S + 1);
        int ret = a * n;
        if (b >= 0) { ret += b * n; printf("%d\n", a * n + b * n); }
        else {
            int c = 0, x = 0;
            for (int i = 2; i <= n; i++) {
                if (S[i] != S[i - 1]) c++;
            }
            c++;
            for (int i = 1; i <= n; i++) {
                if ((i == 1 || S[i] != S[i - 1]) && S[i] == '0') x++;
            }
            printf("%d\n", ret + b * (min(c - x + 1, x + 1)));
        }
    }
    return 0;
}

