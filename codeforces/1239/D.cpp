/* I do it for the glory */
#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
 
#define SZ(x)                       (int) x.size()
#define F                           first
#define S                           second

const int N = 1e6 + 10, MOD = 1e9 + 7;
int t, n, m, gc, C[N], M[N]; vector<int> ts, in[N], out[N];

void preDFS(int v) {
    M[v] = 1;
    for (int u : out[v]) 
        if (!M[u]) preDFS(u);
    ts.push_back(v);
}

void DFS(int v) {
    C[v] = gc; M[v] = 1;
    for (int u : in[v]) 
        if (!M[u]) DFS(u);
}

int main() {
    for (scanf("%d", &t); t && scanf("%d%d", &n, &m); t--, ts = {}, gc = 0) {
        for (int i = 1; i <= n; i++) out[i] = in[i] = {}, M[i] = 0;
        for (int i = 1; i <= m; i++) {
            int u, v; scanf("%d%d", &u, &v);
            if (u != v)
                out[v].push_back(u), in[u].push_back(v);
        }
        for (int i = 1; i <= n; i++) 
            if (!M[i]) preDFS(i);
        reverse(begin(ts), end(ts));
        fill(M, M + n + 2, 0);
        for (int v : ts) 
            if (!M[v]) gc++, DFS(v);
        int ret = 0;
        if (gc < 2) { printf("No\n"); continue; }
        for (int i = 1; i <= n; i++) 
            if (C[i] == gc) ret++;
        printf("Yes\n%d %d\n", n - ret, ret);
        for (int i = 1; i <= n; i++) {
            if (C[i] < gc) printf("%d ", i);
        }
        printf("\n");
        for (int i = 1; i <= n; i++) if (C[i] == gc) printf("%d ", i);
        printf("\n");
    }
    return 0;
}

