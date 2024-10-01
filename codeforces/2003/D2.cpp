#include <bits/stdc++.h>

using namespace std;

constexpr int N = 2e5 + 10;
vector<int> vec[N]; vector<int> adj[N]; 
map<int, int> mp; int mx = 0;

int DFS(int v) {
    if (mp.find(v) != mp.end()) return mp[v];
    mp[v] = v;
    for (int u : adj[v]) mp[v] = max(mp[v], DFS(u));
    return mp[v];
}

long long int get(int l, int r) {
    if (l > r) return 0;
    return 1ll * r * (r + 1) / 2 - 1ll * l * (l - 1) / 2;
}

int main() {
    int q; 
    for (scanf("%d", &q); q--; ) {
        int n, m;  vector<int> st; mx = 0; int bruh = 0; 
        scanf("%d%d", &n, &m); 
        for (int i = 1; i <= n; i++) {
            int l; scanf("%d", &l); vec[i] = {};
            for (; l--; ) { int x; scanf("%d", &x); vec[i].push_back(x); }
            sort(begin(vec[i]), end(vec[i]));
            int fir = -1, sec = -1;
            int ptr = 0;
            for (int j = 0; sec == -1; j++) {
                int f = 0;
                while (ptr < vec[i].size() && vec[i][ptr] == j) { f = 1; ptr++; }
                if (f) { continue; }
                if (fir == -1) fir = j;
                else sec = j;
            }
            adj[fir].push_back(sec); st.push_back(fir); bruh = max(bruh, fir); mx = max(mx, fir);
        }
        mp.clear();
        for (int v : st) { DFS(v); if (adj[v].size() > 1) mx = max(mx, mp[v]); }
        sort(begin(st), end(st)); 
        st.resize(unique(begin(st), end(st)) - begin(st));
        long long ans = 1ll * (min(m + 1, st[0]) - 0) * mx;
        for (int i = 0; i < st.size(); i++) {
            if (st[i] > m) break;
            ans += max(mx, DFS(st[i]));
            if (i + 1 == st.size() || st[i + 1] > m) ans += 1ll * max(0, (min(m, mx) - st[i])) * mx + get(max(st[i], mx) + 1, m);
            else ans += 1ll * max(0, (min(st[i + 1], mx) - st[i] - 1)) * mx + get(max(mx, st[i] + 1), st[i + 1] - 1);
        }
        // printf("\n");
        for (int i = 0; i <= bruh; i++) adj[i] = {};
        printf("%lld\n", ans);
    }
}