/* I do it for the glory */
#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
 
#define SZ(x) (int) x.size()
#define F first
#define S second

const int N = 1e6 + 10, MOD = 1e9 + 7;
int n, m, C[N], c, q;

void add(int u, int v) {
    c -= (!C[v]);
    c -= (!C[u]);
    if (u > v) C[v]++;
    else C[u]++;
    c += (!C[v]);
    c += (!C[u]);
}

void rem(int u, int v) {
    c -= (!C[v]);
    c -= (!C[u]);
    if (u > v) C[v]--;
    else C[u]--;
    c += (!C[v]);
    c += (!C[u]);
}

int main() {
    scanf("%d%d", &n, &m);
    c = n;
    for (int i = 1; i <= m; i++) {
        int u, v; scanf("%d%d", &u, &v);
        add(u, v);
    }
    scanf("%d", &q);
    for (; q; q--) {
        int t, u, v; scanf("%d", &t);
        if (t < 3) scanf("%d%d", &u, &v);
        if (t < 2) add(u, v);
        else if (t < 3) rem(u, v);
        else printf("%d\n", c);
    }
    return 0;
}

