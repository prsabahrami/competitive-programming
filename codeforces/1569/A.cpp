/* Just a drop of water in an endless sea */
#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
 
#define SZ(x) (int) x.size()
#define F first
#define S second

const int N = 1e6 + 10, MOD = 1e9 + 7;
char S[N]; int t, n;

int main() {
    scanf("%d", &t);
    for (; t; t--) {
        scanf("%d", &n);
        scanf("%s", S + 1);
        pii ret = {-1, -1};
        for (int i = 1; i <= n; i++) {
            int c = 0;
            for (int j = i; j <= n; j++) {
                c += (S[j] == 'a' ? 1 : -1);
                if (!c) ret = {i, j};
            }
        }
        printf("%d %d\n", ret.F, ret.S);
    }
    return 0;
}

