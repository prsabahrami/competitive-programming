#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
 
#define SZ(x)                       (int) x.size()
#define F                           first
#define S                           second

const int N = 5e5 + 10, MOD = 1e9 + 7;
int H[N], W[N], B[N], M[1 << 22], A[N], S[N], n;
vector<pii> adj[N];

void preDFS(int v) {
    S[v] = 1;
    for (pii u : adj[v]) {
        H[u.F] = H[v] + 1;
        W[u.F] = W[v] ^ u.S;
        preDFS(u.F);
        S[v] += S[u.F];
        if (S[u.F] > S[B[v]]) B[v] = u.F;
    }
}

void undo(int v) {
    M[W[v]] = -MOD;
    for (pii u : adj[v]) {
        undo(u.F);
    }
}

void add(int v) {
    M[W[v]] = max(M[W[v]], H[v]);
    for (pii u : adj[v]) {
        add(u.F);
    }
}

void update(int v, int p) {
   for (int i = 0; i < 1 << 22; i = (i ? i << 1 : i + 1)) A[p] = max(A[p], H[v] + M[i ^ W[v]] - 2 * H[p]);
   for (pii u : adj[v]) {
       update(u.F, p);
   }
}

void DFS(int v) {
    if (!SZ(adj[v])) {
        M[W[v]] = H[v];
        return;
    }
    for (pii u : adj[v]) {
        if (u.F != B[v]) {
            DFS(u.F);
            undo(u.F);
        }
    }
    DFS(B[v]);
    M[W[v]] = max(M[W[v]], H[v]);
    for (int i = 0; i < 1 << 22; i = (i ? i << 1 : i + 1)) A[v] = max(A[v], M[i ^ W[v]] - H[v]);
    for (pii u : adj[v]) {
        if (u.F != B[v]) 
            update(u.F, v), add(u.F);
    }
}

void SFD(int v) {
    for (pii u : adj[v]) {
        SFD(u.F);
        A[v] = max(A[v], A[u.F]);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
        int p; char c; scanf("%d %c\n", &p, &c);
        adj[p].push_back({i, (1 << (c - 'a'))});
    }
    preDFS(1);
    fill(M, M + (1 << 22), -MOD);
    DFS(1);
    SFD(1);
    for (int i = 1; i <= n; i++) printf("%d ", A[i]);   
    return 0;
}
