/* I do it for the glory */
#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
 
#define SZ(x) (int) x.size()
#define F first
#define S second

const int N = 1e5 + 10, MOD = 1e9 + 7;
int dp[2][N], n, ret; vector<int> adj[N];

void DFS(int v, int p = -1) {
    int c = 0; dp[1][v] = 1;
    for (int u : adj[v]) {
        if (u != p) DFS(u, v), c++;
    }
    for (int u : adj[v]) 
        if (u != p) ret = max(ret, dp[1][v] + dp[0][u]), 
            dp[1][v] = max(dp[1][v], 1 + dp[0][u]), 
            dp[0][v] = max(dp[0][v], c - 1 + max(dp[0][u], dp[1][u]));
    vector<int> vec;
    for (int &u : adj[v]) 
        if (u != p) vec.push_back(max(dp[0][u], dp[1][u]));
    sort(begin(vec), end(vec), greater<int>());
    if (SZ(vec) < 2) return;
    ret = max(ret, vec[0] + vec[1] + SZ(adj[v]) - 2);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int u, v; scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(1);
    printf("%d\n", ret);
    return 0;
}

