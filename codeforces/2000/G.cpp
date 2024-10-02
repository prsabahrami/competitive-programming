#include <bits/stdc++.h>

typedef long long int ll;

using namespace std;
constexpr int N = 1e5 + 10, MOD = 1e9 + 7;
vector<tuple<int, int, int>> adj[N];
ll dp[N], pd[N]; int M[N];

int main() {
    int q; scanf("%d", &q);
    for (; q--; ) {
        int n, m;
        scanf("%d%d", &n, &m);
        int t0, t1, t2; scanf("%d%d%d", &t0, &t1, &t2);
        for (int i = 1; i <= m; i++) {
            int u, v, l1, l2; scanf("%d%d%d%d", &u, &v, &l1, &l2);
            adj[u].push_back({v, l1, l2});
            adj[v].push_back({u, l1, l2});
        }
        priority_queue<pair<int, int>> pq;
        for (int i = 1; i <= n; i++) dp[i] = 1e18, M[i] = 0, pd[i] = 1e18;
        pq.push({dp[n] = 0, n});
        while (!pq.empty()) {
            auto[d, v] = pq.top(); pq.pop();
            if (M[v]) continue;
            M[v] = 1; d *= -1;
            for (auto[u, l1, l2] : adj[v]) {
                if (d + l1 > t0 - t2) continue;
                printf("bruh\n");
                if (dp[u] > d + l1) {
                    dp[u] = d + l1;
                    pq.push({-dp[u], u});
                }
            }
        }
        if (dp[1] < 1e18) {
            printf("%d\n", t0 - dp[1]);
            continue;
        }
        for (int i = 1; i <= n; i++) {
            if (M[i]) dp[i] = t0 - t2, pq.push({-dp[i], i}), M[i] = 0;
        }
        while (!pq.empty()) {
            auto[d, v] = pq.top(); pq.pop();
            if (M[v]) continue;
            M[v] = 1; d *= -1;
            for (auto[u, l1, l2] : adj[v]) {
                if (dp[u] > dp[v] + l2) {
                    dp[u] = dp[v] + l2;
                    pq.push({-dp[u], u});
                }
            }
        }
        for (int i = 1; i <= n; i++) M[i] = 0;
        pd[1] = 0;
        pq.push({0, 1});
        while (!pq.empty()) {
            auto[d, v] = pq.top(); pq.pop();
            if (M[v]) continue;
            M[v] = 1;
            d *= -1;
            for (auto[u, l1, l2] : adj[v]) {
                if (d + l1 > t1) continue;
                if (pd[u] > d + l1) {
                    pd[u] = d + l1;
                    pq.push({-pd[u], u});
                }
            }
        }
        ll ans = -1;
        for (int i = 1; i <= n; i++) {
            if (M[i]) ans = max(ans, t0 - pd[i] - dp[i]), printf("%d %d %d\n", i, pd[i], dp[i]);
        }
        printf("%lld\n", ans);
        
    }
    return 0;
}