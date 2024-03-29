/**
    * code generated by JHelper
    * More info: https://github.com/AlexeyDmitriev/JHelper
    * @author Rick From Rickland
*/

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

const ll MAXN = 2e5 + 10;
const ll MAXA = 501;
const ll INF = 8e18;
const ll MOD = 998244353; //1e9 + 7
const ld PI = 4 * atan((ld) 1);

ll dist[MAXA][MAXA], cnt[MAXA][MAXA], Edge[MAXA][MAXA], n, m;

void Floyd_Warshall() {
    for (ll k = 1; k <= n; k++) {
        for (ll i = 1; i <= n; i++) {
            for (ll j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    return;
}
int main() {
    fast_io;
    set_random;
    memset(dist, 63, sizeof dist), memset(Edge, -1, sizeof Edge);
    for (ll i = 0; i < MAXA; i++) dist[i][i] = 0;
    cin >> n >> m;
    for (ll i = 1; i <= m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = dist[v][u] = w;
        Edge[u][v] = Edge[v][u] = w;
    }
    Floyd_Warshall();
    for (ll k = 1; k <= n; k++) {
        for (ll i = 1; i <= n; i++) {
            for (ll j = 1; j <= n; j++) {
                if (Edge[k][j] == -1) continue;
                if (dist[i][j] == dist[i][k] + Edge[k][j]) {
                    cnt[i][j]++;
                }
            }
        }
    }
    //cout << cnt[1][2] << sep << cnt[1][4] << sep << cnt[1][3] << endl;
    for (ll i = 1; i <= n; i++) {
        for (ll j = i + 1; j <= n; j++) {
            ll ans = 0;
            for (ll k = 1; k <= n; k++) {
                if (dist[i][j] != dist[i][k] + dist[k][j]) continue;
                ans += cnt[i][k];
            }
            cout << ans << sep;
        }
    }
    return 0;
}
