#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

#define SZ(x) (int) (x).size()

constexpr int N = 2e5 + 10;
int P[19][N], H[N], St[N], V[N], S[N], A[N], Ft[N], ret[N], n, q, ts;
vector<int> adj[N], G[N];

void preDFS(int v, int p = -1) {
    if (!~p) P[0][v] = v;
    St[v] = ts++;
    for (int i = 1; i < 19; i++)
        P[i][v] = P[i - 1][P[i - 1][v]];
    for (int &u : adj[v])
        if (u != p) H[u] = H[v] + 1, P[0][u] = v, preDFS(u, v);
    Ft[v] = ts;
}

int LCA(int u, int v) {
    if (H[u] < H[v]) swap(u, v);
    for (int i = H[u] - H[v]; i; i -= i & -i)
        u = P[__builtin_ctz(i)][u];
    for (int i = 18; ~i; i--) 
        if (P[i][u] != P[i][v]) 
            u = P[i][u], v = P[i][v];
    return u ^ v ? P[0][v] : v;
}

int D(int u, int v) { return H[u] + H[v] - 2 * H[LCA(u, v)]; }

int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int u, v; scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    preDFS(1);
    for (scanf("%d", &q); q; q--) {
        int k, m; scanf("%d%d", &k, &m);
        vector<int> vec;
        for (int i = 1; i <= k; i++) 
            scanf("%d%d", &V[i], &S[i]), vec.push_back(V[i]);
        for (int i = 1; i <= m; i++) 
            scanf("%d", &A[i]), vec.push_back(A[i]);
        sort(begin(vec), end(vec)); vec.resize(unique(begin(vec), end(vec)) - begin(vec));
        sort(begin(vec), end(vec), [&] (int u, int v) { return St[u] < St[v]; });
        int M = SZ(vec);
        for (int i = 0; i < M; i++) 
            vec.push_back(LCA(vec[i], vec[(i + 1) % M]));
        sort(begin(vec), end(vec)); vec.resize(unique(begin(vec), end(vec)) - begin(vec));
        sort(begin(vec), end(vec), [&] (int u, int v) { return St[u] < St[v]; });
        vector<int> st = {vec[0]};
        for (int i = 1; i < SZ(vec); st.push_back(vec[i]), i++) {
            int v = vec[i], p = st.back();
            for (; St[p] > St[v] || Ft[p] < Ft[v]; st.pop_back(), p = st.back());
            assert(SZ(st));
            G[v].push_back(p);
            G[p].push_back(v);
        }
        set<array<int, 3>> pq;
        for (int i = 1; i <= k; i++) pq.insert({-1, i, V[i]});
        for (; SZ(pq); ) {
            auto[t, id, v] = *pq.begin(); pq.erase(pq.begin());
            if (ret[v]) continue;
            ret[v] = id;
            //printf("%d %d\n", v, ret[v]);
            for (int &u : G[v]) 
                if (!ret[u]) 
                    pq.insert({(D(V[id], u) - 1) / S[id], id, u});
        }
        for (int i = 1; i <= m; i++) printf("%d ", ret[A[i]]);
        for (int &v : vec) 
            ret[v] = 0, G[v] = {};
        printf("\n");
    }
    return 0;
}