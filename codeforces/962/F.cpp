#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
 
#define SZ(x)                       (int) x.size()
#define F                           first
#define S                           second

const int N = 1e5 + 10;
int H[N], M[N], kir[N], khar[N], P[N], n, m;
vector<int> adj[N], A; pii E[N];

void preDFS(int v, int p = -1) {
    M[v] = 1;
    for (int u : adj[v]) {
        if (u == p) continue;
        if (M[u] && H[u] < H[v]) kir[v]++, kir[u]--;
        else if (!M[u]) H[u] = H[v] + 1, preDFS(u, v);
    }
}

void psDFS(int v) {
    M[v] = 1;
    for (int u : adj[v]) {
        if (!M[u]) psDFS(u), kir[v] += kir[u];
    }
}

void kirDFS(int v) {
    M[v] = 1;
    for (int u : adj[v]) {
        if (!M[u]) {
            P[u] = P[v] + (kir[u] == 1);
            kirDFS(u);
        }
    }
}

void coronaDFS(int v, int p = -1) {
    M[v] = 1;
    for (int u : adj[v]) {
        if (u == p) continue;
        if (M[u] && H[u] < H[v] && P[v] - P[u] != H[v] - H[u]) {
            khar[v]++, khar[u]--;
        } else if (!M[u]) coronaDFS(u, v);
    }
}

void kharDFS(int v) {
    M[v] = 1;
    for (int u : adj[v]) {
        if (!M[u]) {
            kharDFS(u), khar[v] += khar[u];
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v; scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
        E[i] = {u, v};
    }
    for (int i = 1; i <= n; i++) if (!M[i]) preDFS(i);
    memset(M, 0, sizeof M);
    for (int i = 1; i <= n; i++) if (!M[i]) psDFS(i);
    memset(M, 0, sizeof M);
    for (int i = 1; i <= n; i++) if (!M[i]) kirDFS(i);
    memset(M, 0, sizeof M);
    for (int i = 1; i <= n; i++) if (!M[i]) coronaDFS(i);
    memset(M, 0, sizeof M);
    for (int i = 1; i <= n; i++) if (!M[i]) kharDFS(i);
    for (int i = 1; i <= m; i++) {
        int u, v; tie(u, v) = E[i];
        if (H[u] > H[v]) swap(u, v);
        if (kir[v] == 1 && !khar[v]) A.push_back(i);
    }
    printf("%d\n", SZ(A));
    for (int x : A) printf("%d ", x);
    return 0;
}
