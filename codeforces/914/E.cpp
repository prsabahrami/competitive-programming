#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
 
#define SZ(x)                       (int) x.size()
#define F                           first
#define S                           second

const int N = 2e5 + 10;
int A[N], H[N], M[N], C[1 << 20], S[N], n; ll P[N], R[N];
vector<int> adj[N];


void preDFS(int v, int p = -1) {
    S[v] = 1;
    for (int u : adj[v]) {
        if (!M[u] && u != p) preDFS(u, v), S[v] += S[u];
    }
}

int centroid(int v, int s, int p = -1) {
    for (int u : adj[v]) {
        if (!M[u] && u != p && S[u] * 2 > s) return centroid(u, s, v);
    }
    return v;
}

void DFS(int v, int p = -1) {
    for (int u : adj[v]) {
        if (M[u] || u == p) continue;
        H[u] = H[v] ^ A[u];
        DFS(u, v);
    }
}

void add(int v, int p = -1) {
    C[H[v]]++;
    for (int u : adj[v]) {
        if (!M[u] && u != p) {
            add(u, v);
        }
    }
}

void calc(int v, int p, int t, int x) {
    for (int i = 0; i < 1 << 20; i = (i ? i << 1 : i + 1)) P[v] += t * C[H[v] ^ x ^ i];
    for (int u : adj[v]) {
        if (!M[u] && u != p) {
            calc(u, v, t, x);
        }
    }
}

void remove(int v, int p = -1) {
    C[H[v]]--;
    for (int u : adj[v]) {
        if (u != p && !M[u]) {
            remove(u, v);
        }
    }
}

void SFD(int v, int p = -1) {
    for (int u : adj[v]) {
        if (u != p && !M[u]) {
            SFD(u, v);
            P[v] += P[u];
        }
    }
    R[v] += P[v];
}

void CLEAR(int v, int p = -1) {
    for (int u : adj[v]) {
        if (!M[u] && u != p) CLEAR(u, v);
    }
    P[v] = 0;
}

void solve(int v) {
    add(v);
   // for (int i = 1; i <= n; i++) printf("%d ", H[i]);
    //printf("\n");
    calc(v, -1, 1, A[v]);
    remove(v);
    for (int u : adj[v]) {
        if (!M[u]) {
            add(u, v);
            calc(u, v, -1, A[v]);
            remove(u, v);
        }
    }
    //for (int i = 1; i <= n; i++) printf("%d %lld\n", i, P[i]);
    SFD(v);
    R[v] -= P[v]; P[v] = (P[v] - 1) / 2; R[v] += P[v];
    CLEAR(v);
}

void decompose(int v) {
    preDFS(v);
    v = centroid(v, S[v]);
    DFS(v);
    //solve
    solve(v);
    M[v] = 1;
    for (int u : adj[v]) {
        if (!M[u]) decompose(u);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int u, v; scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        char c; cin >> c;
        A[i] = (1 << (c - 'a'));
    }
    decompose(1);
    //DFS(3);
    //solve(3);
    for (int i = 1; i <= n; i++) {
        printf("%lld ", R[i] + 1);
    }
    return 0;
}
