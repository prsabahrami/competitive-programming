/* I do it for the glory */
#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
 
#define SZ(x) (int) x.size()
#define F first
#define S second
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int Pow(int a, int b, int md, int ret = 1) {
    for (; b; b >>= 1, a = 1ll * a * a % md)
        if (b & 1) ret = 1ll * ret * a % md;
    return ret;
}

const int N = 1e5 + 10, mds[] = {(int) 1e9 + 7}, 
    bses[] = {4001};
int up[N], dn[N], ret[N], MOD, base, n;
vector<int> adj[N]; map<int, int> mp; int tot;

void add(int x) {
    tot += !mp[x];
    mp[x]++;
}

void rem(int x) {
    mp[x]--;
    tot -= !mp[x];
}

void dnDFS(int v, int p = -1) {
    dn[v] = 1;
    for (int &u : adj[v]) 
        if (u != p) dnDFS(u, v), dn[v] = (dn[v] + Pow(base, dn[u], MOD)) % MOD;
}

void DFS(int v, int p = -1) {
    ret[v] = tot;
    for (int &u : adj[v]) {
        if (u != p) {
            rem(dn[v]), rem(dn[u]);
            dn[v] = (dn[v] - Pow(base, dn[u], MOD) + MOD) % MOD;
            dn[u] = (dn[u] + Pow(base, dn[v], MOD)) % MOD; add(dn[u]), add(dn[v]);
            DFS(u, v);
            rem(dn[v]), rem(dn[u]);
            dn[u] = (dn[u] - Pow(base, dn[v], MOD) + MOD) % MOD;
            dn[v] = (dn[v] + Pow(base, dn[u], MOD)) % MOD; add(dn[v]), add(dn[u]);
        }
    }
}

int main() {
    MOD = mds[rng() % 1], base = bses[rng() % 1];
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int u, v; scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dnDFS(1);
    for (int i = 1; i <= n; i++) 
        add(dn[i]);
    DFS(1);
    int v = 1;
    for (int i = 1; i <= n; i++) 
        if (ret[i] > ret[v]) v = i;
    printf("%d\n", v);
    return 0;
}
//
