#pragma GCC optimize("O2")

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef pair<string, string> pss;
typedef pair<pll, ll> ppl;
typedef pair<ll, pll> plp;
typedef pair<pll, pll> ppp;

template<class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//order_of_key , find_by_order
#define sz(x)                       (ll) x.size()
#define jjoin(x)                    for (auto i : x) cout << i << endl;
#define all(x)                      (x).begin(),(x).end()
#define F                           first
#define S                           second
#define Mp                          make_pair
#define sep                         ' '
#define error(x)                    cerr << #x << " = " << x << endl
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define set_random                  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define kill(x)                     return cout << x << endl , 0;
#define Hkill(x)                    cout << x << endl; exit(0);
#define endl                        '\n'

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 3e3 + 10;
const ll MAXA = 101;
const ll INF = 1e14;
const ll MOD = 998244353; //1e9 + 7
const ld PI = 4 * atan((ld) 1);

pll Par[MAXN][MAXN];
ll dist[MAXN][MAXN], n, m, k;
vector<ll> adj[MAXN];
set<ppl> Mark;
void bfs() {
    memset(dist, 63, sizeof dist);
    queue<pll> Q;
    for (ll u : adj[1]) {
        dist[1][u] = 1;
        Q.emplace(1, u);
    }
    while (sz(Q)) {
        ll v = Q.front().S, u = Q.front().F;
        Q.pop();
        for (ll w : adj[v]) {
            if (Mark.find({{u, v}, w}) != Mark.end()) continue;
            if (dist[v][w] > dist[u][v] + 1) {
                dist[v][w] = dist[u][v] + 1;
                Par[v][w] = {u, v};
                Q.emplace(v, w);
            }
        }
    }
    return;
}
int main() {
    fast_io;
    set_random;
    cin >> n >> m >> k;
    for (ll i = 1; i <= m; i++) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v), adj[v].push_back(u);
    }
    for (ll i = 1; i <= k; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        Mark.insert({{u, v}, w});
    }
    bfs();
    vector<ll> ans;
    pll cur = {-1, n};
    ll MN = INF;
    for (ll i = 1; i <= n; i++) {
        if (dist[i][n] < MN) {
            MN = dist[i][n], cur = {i, n};
        }
    }
    if (MN >= INF) kill(-1);
    cout << MN << endl;
    ans.push_back(n);
    while (cur.F != 1) {
        ans.push_back(cur.F);
        cur = Par[cur.F][cur.S];
    }
    ans.push_back(1);
    reverse(all(ans));
    for (ll x : ans) cout << x << sep;
    cout << endl;
    return 0;
}
