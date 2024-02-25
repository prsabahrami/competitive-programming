/* I do it for the glory */
#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
 
#define SZ(x) (int) x.size()
#define F first
#define S second

const int N = 1e6 + 10, MOD = 1e9 + 7;
set<pii> st; set<int> adj[N], g[N];
int n, rt[N], fr2[N], to2[N], fr[N], to[N], eid; set<pii> E;

int Find(int v) {
    return !rt[v] ? v : rt[v] = Find(rt[v]);
}

void Union(int u, int v) {
    v = Find(v), u = Find(u);
    if (u == v) return;
    if (SZ(adj[v]) + SZ(g[v]) < SZ(adj[u]) + SZ(g[u])) swap(u, v);
    for (int id : g[u]) {
        int U = fr[id], V = to[id];
        if (Find(U) ^ u) swap(U, V); assert(Find(U) == u);
        if (Find(V) ^ v) g[v].insert(id);
        else g[v].erase(id);
    }
    for (int id : adj[u]) {
        int U = fr2[id], V = to2[id];
        if (Find(U) ^ u) swap(U, V); assert(Find(U) == u);
        if (Find(V) ^ v) adj[v].insert(id);
        else adj[v].erase(id);
    }
    g[u] = {}, adj[u] = {}; rt[u] = v;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int u, v; scanf("%d%d", &u, &v); E.insert({u, v}); fr2[i] = u, to2[i] = v;
        adj[u].insert(i);
        adj[v].insert(i); 
    }
    int ret = n - 1; eid = n - 1;
    for (int i = 1; i < n; i++) {
        int u, v; scanf("%d%d", &u, &v), fr[i] = u, to[i] = v;
        g[u].insert(i), g[v].insert(i);
    }
    for (int i = 1; i < n; i++) {
        int u = fr[i], v = to[i];
        if (E.count({u, v}) || E.count({v, u})) 
            Union(u, v), ret--;
    }
    printf("%d\n", ret);
    for (int i = 1; i <= n; i++) {
        if (Find(i) == i) st.insert({SZ(adj[i]), i});
    }
    //~ for (int i = 1; i <= n; i++) {
        //~ if (Find(i) == i) {
            //~ printf("$1 %d\n", i);
            //~ for (int id : adj[i]) printf("%d ", id);
            //~ printf("\n$2 %d\n", i);
            //~ for (int id : g[i]) printf("%d ", id);
            //~ printf("\n");
        //~ }
    //~ }
    while (SZ(st) > 1) {
        int v = st.begin()->S; st.erase(st.begin());
        if (Find(v) != v || adj[v].empty()) { st.erase(st.begin()); continue; }
        int id = *adj[v].begin(), p; adj[v].erase(id);
        printf("%d %d ", fr2[id], to2[id]);
        p = Find(Find(fr2[id]) ^ v ? fr2[id] : to2[id]);
        adj[p].erase(id);
        st.erase({SZ(adj[p]) + 1, p});
        st.insert({SZ(adj[p]), p});
        id = *g[v].begin();
        printf("%d %d\n", fr[id], to[id]);
        eid++; fr2[eid] = fr[id], to2[eid] = to[id];
        p = Find(Find(fr[id]) ^ v ? fr[id] : to[id]);
        st.erase({SZ(adj[p]), p});
        adj[v].insert(eid); adj[Find(Find(fr[id]) ^ v ? fr[id] : to[id])].insert(eid);
        Union(v, p);
        st.insert({SZ(adj[Find(v)]), Find(v)});
    }
    return 0;
}

