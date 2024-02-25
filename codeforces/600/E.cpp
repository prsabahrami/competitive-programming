#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
 
#define SZ(x)                       (int) x.size()
#define F                           first
#define S                           second

const int N = 1e5 + 10, MOD = 1e9 + 7;
int C[N], M[N], n; ll R[N], K[N];
vector<int> adj[N]; map<int, int> mp[N];

void DFS(int v, int p = -1) {
    mp[v][C[v]] = M[v] = 1; R[v] = C[v];
    for (int u : adj[v]) {
        if (u != p) {
            DFS(u, v);
            if (SZ(mp[u]) > SZ(mp[v])) {
                swap(R[v], R[u]);
                swap(M[v], M[u]);
                mp[v].swap(mp[u]);
            }
            for (pii x : mp[u]) {
                mp[v][x.F] += x.S;
                if (mp[v][x.F] > M[v]) {
                    M[v] = mp[v][x.F];
                    R[v] = x.F;
                } else if (mp[v][x.F] == M[v]) {
                    R[v] += x.F;
                }
            }
        }
    } 
    K[v] = R[v];  
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &C[i]);
    for (int i = 1; i < n; i++) {
        int u, v; scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(1);
    for (int i = 1; i <= n; i++) {
        printf("%lld ", K[i]);
    }
    printf("\n");
	return 0;
}
