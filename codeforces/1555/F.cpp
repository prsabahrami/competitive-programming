/* I do it for the glory */
#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
 
#define SZ(x) (int) x.size()
#define F first
#define S second

const int N = 5e5 + 10, MOD = 1e9 + 7;
vector<int> adj[N]; int ts;
int M2[N], fr[N], to[N], w[N], X[N], rt[N], F[2][N], St[N], hd[N], hv[N], S[N], M[N], P[N], H[N], n, q;

void upd(int id, int p, int x) {
    for (p += 2; p < N; p += p & -p) F[id][p] += x;
}
 
int _get(int id, int p) {
    int res = 0;
    for (p += 2; p; p -= p & -p) res += F[id][p];
    return res;
}
 
void add(int l, int r, int x) {
    if (l > r) return;
    upd(0, l, x), upd(0, r + 1, -x);
    upd(1, l, x * (l - 1)), upd(1, r + 1, -x * r);
}
 
int get(int r) {
    return _get(0, r) * r - _get(1, r);
}
 
int get(int l, int r) {
    if (l > r) return 0;
    return get(r) - get(l - 1);
}
 
int Find(int v) { return !rt[v] ? v : rt[v] = Find(rt[v]); }

int Union(int u, int v) {
    u = Find(u), v = Find(v);
    if (u ^ v) return rt[u] = v, 1;
    return 0;
}

void preDFS(int v, int p = -1) {
    M2[v] = S[v] = 1; 
    for (int &id : adj[v]) {
        int u = fr[id] ^ to[id] ^ v;
        if (u != p) H[u] =  H[v] + 1, P[u] = v, X[u] = X[v] ^ w[id], preDFS(u, v), S[v] += S[u];
    }
    for (int &id : adj[v]) {
        int u = fr[id] ^ to[id] ^ v;
        if (u != p && S[u] > S[hv[v]]) hv[v] = u;
    }
}

void hlDFS(int v, int p = -1) {
    St[v] = ++ts;
    if (!~p) hd[v] = v;
    if (hv[v]) hd[hv[v]] = hd[v], hlDFS(hv[v], v);
    for (int &id : adj[v]) {
        int u = fr[id] ^ to[id] ^ v;
        if (u != p && u != hv[v]) hlDFS(hd[u] = u, v);
    }
}

int main() {
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= q; i++) {
        scanf("%d%d%d", &fr[i], &to[i], &w[i]);
        if (Union(fr[i], to[i]))    
            M[i] = 1, adj[fr[i]].push_back(i), adj[to[i]].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        if (!M2[i]) preDFS(i), hlDFS(i);
    }
    for (int i = 1; i <= q; i++) {
        if (M[i]) { printf("YES\n"); continue; }
        int u = fr[i], v = to[i], x = w[i], f = 0;
        if (x ^ X[u] ^ X[v] ^ 1) { printf("NO\n"); continue; }
        for (; hd[v] != hd[u]; ) 
            if (H[hd[v]] > H[hd[u]]) f += get(St[hd[v]], St[v]), v = P[hd[v]];
            else f += get(St[hd[u]], St[u]), u = P[hd[u]];
        if (H[u] < H[v]) swap(u, v);
        f += get(St[v] + 1, St[u]);
        if (f) { printf("NO\n"); continue; }
        v = fr[i], u = to[i];
        for (; hd[v] != hd[u]; ) 
            if (H[hd[v]] > H[hd[u]]) add(St[hd[v]], St[v], 1), v = P[hd[v]];
            else add(St[hd[u]], St[u], 1), u = P[hd[u]];
        if (H[u] < H[v]) swap(u, v);
        add(St[v] + 1, St[u], 1);
        printf("YES\n");
    }
    return 0;
}

