#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
 
#define SZ(x)                       (int) x.size()
#define F                           first
#define S                           second

const int N = 1e6 + 10, MOD = 1e9 + 7;
int nxt[N], pw[N], n, q; char S[N], C[N];
char Q[N]; string wtf[N];

int main() {
    scanf("%s", S);
    n = strlen(S);
    scanf("%d", &q);
    for (int i = 1; i <= q; i++) {
        scanf("%s", C);
        Q[i] = C[0];
        int l = strlen(C);
        for (int j = 3; j < l; j++) {
            wtf[i] += C[j];
        }
    }   
    for (int i = 0; i < 10; i++) nxt[i] = i, pw[i] = 10;
    for (int i = q; i; i--) {
        int tpw = 1, tnxt = 0;
        for (char c : wtf[i]) {
            tnxt = (1ll * tnxt * pw[c - '0'] % MOD + nxt[c - '0']) % MOD;
            tpw = 1ll * tpw * pw[c - '0'] % MOD;
        }
        pw[Q[i] - '0'] = tpw;
        nxt[Q[i] - '0'] = tnxt;
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        res = 1ll * res * pw[S[i] - '0'] % MOD;
        res = (res + nxt[S[i] - '0']) % MOD;
    }
    printf("%d\n", res);
    return 0;
}
