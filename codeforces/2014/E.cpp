#include <bits/stdc++.h>

typedef long long int ll;


using namespace std;
constexpr int N = 2e5 + 10; ll MOD = 1e17 + 7;
ll M[N], dp[2][N]; vector<pair<ll, ll>> adj[N]; ll tmp[N]; vector<int> vec;

void dijk(int st, int n, int t) {
  for (int i = 1; i <= n; i++) dp[t][i] = MOD, M[i] = 0, tmp[i] = MOD;
  priority_queue<pair<ll, int>> pq;
  dp[t][st] = 0;
  pq.push({0, st});
  while (!pq.empty()) {
    auto[d, v] = pq.top(); pq.pop();
    if (M[v]) continue;
    M[v] = 1;
    d *= -1;
    for (auto[u, w] : adj[v]) {
      if (dp[t][u] > d + w) {
        dp[t][u] = d + w;
        pq.push({-dp[t][u], u});
      }
    }
  }
  for (int i = 1; i <= n; i++) M[i] = 0;
  for (int v : vec) pq.push({-(tmp[v] = dp[t][v]), v});
  while (!pq.empty()) {
    auto[d, v] = pq.top(); pq.pop();
    if (M[v]) continue;
    M[v] = 1;
    d *= -1;
    for (auto[u, w] : adj[v]) {
      if (tmp[u] > d + w / 2) {
        tmp[u] = d + w / 2;
        pq.push({-tmp[u], u});
      }
    }
  }
  for (int i = 1; i <= n; i++) dp[t][i] = min(dp[t][i], tmp[i]);
}

int main() {
  int q;
  for (scanf("%d", &q); q--; ) {
    int n, m, h;
    scanf("%d%d%d", &n, &m, &h);
    vec = {};
    for (int i = 1; i <= n; i++) adj[i] = {};
    for (int i = 0; i < h; i++) { int v; scanf("%d", &v); vec.push_back(v); }
    for (int i = 0; i < m; i++) {
      int u, v, w; scanf("%d%d%d", &u, &v, &w);
      adj[u].push_back({v, w});
      adj[v].push_back({u, w});
    }
    dijk(1, n, 0);
    dijk(n, n, 1);

    ll ans = MOD;

    for (int i = 1; i <= n; i++) ans = min(ans, max(dp[1][i], dp[0][i]));

    if (ans == MOD) printf("%d\n", -1);
    else printf("%lld\n", ans);

  }

}

