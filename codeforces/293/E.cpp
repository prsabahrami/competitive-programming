#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
 
#define SZ(x)                       (int) x.size()
#define F                           first
#define S                           second

const int N = 1e5 + 10;
int D[N], H[N], M[N], S[N], fen[N], n, L, W; ll R = 0, tot = 0;
vector<pii> adj[N], vec, tmp;

void upd(int pos, int x) {
    for (pos++; pos < N; pos += pos & -pos) fen[pos] += x;
}

int get(int pos) {
    int res = 0;
    if (pos < 0) return 0;
    for (pos++; pos; pos -= pos & -pos) {
        res += fen[pos];        
    }
    return res;
}

void preDFS(int v, int p = -1) {
    S[v] = 1;
    for (pii u : adj[v]) 
        if (u.F != p && !M[u.F]) 
            preDFS(u.F, v), S[v] += S[u.F];
}

void DFS(int v, int p = -1) {
    for (pii u : adj[v]) {
        if (u.F != p && !M[u.F]) {
            H[u.F] = H[v] + 1;
            D[u.F] = D[v] + u.S;
            DFS(u.F, v);
        }
    }
}

void SFD(int v, int p = -1) {
    tmp.push_back({D[v], H[v]});
    for (pii u : adj[v]) {
        if (!M[u.F] && u.F != p) {
            SFD(u.F, v);
        }
    }
}

int centroid(int v, int s, int p = -1) {
    for (pii u : adj[v]) {
        if (u.F != p && !M[u.F] && S[u.F] * 2 > s) return centroid(u.F, s, v);
    }
    return v;
}

ll solve(int v) {
    tot = 0;
    vec = {{D[v], H[v]}};
    for (pii u : adj[v]) {
        if (!M[u.F]) {
            SFD(u.F, v);
            sort(tmp.begin(), tmp.end());
            int ptr = 0;
            for (int i = SZ(tmp) - 1; i >= 0; i--) {
                while (ptr < SZ(vec) && vec[ptr].F + tmp[i].F <= W) upd(vec[ptr++].S, 1);
                tot += get(L - tmp[i].S);
            }
            while (ptr) upd(vec[--ptr].S, -1);
            for (pii x : tmp) vec.push_back(x);
            sort(vec.begin(), vec.end());
            tmp = {};
        }
    }
    return tot;
 }

void decompose(int v) {
    preDFS(v);
    v = centroid(v, S[v]);
    H[v] = D[v] = 0;  DFS(v);
    //solve 
    R += solve(v);
    M[v] = 1;
    for (pii u : adj[v]) {
        if (!M[u.F]) decompose(u.F);
    }
}

int main() {
    scanf("%d%d%d", &n, &L, &W);
    for (int i = 2; i <= n; i++) {
        int p, w; scanf("%d%d", &p, &w);
        adj[p].push_back({i, w});
        adj[i].push_back({p, w});
    }
    decompose(1);
    printf("%lld\n", R);
    return 0;
}
