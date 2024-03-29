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

const ll MAXN = 1e3 + 10;
const ll MAXA = 101;
const ll INF = 8e18;
const ll MOD = 998244353; //1e9 + 7
const ld PI = 4 * atan((ld) 1);
ll dist[MAXN][MAXN], Circ[MAXN], n, m, k;
pll A[MAXN];
plp C[MAXN];
vector<ll> adj[MAXN + MAXN];

bool Coin(plp x, plp y) {
    return ((x.S.F - y.S.F) * (x.S.F - y.S.F) + (x.S.S - y.S.S) * (x.S.S - y.S.S) <= (y.F * y.F));
}

bool Coincide(pll x, plp y) {
    return ((x.F - y.S.F) * (x.F - y.S.F) + (x.S - y.S.S) * (x.S - y.S.S) <= (y.F * y.F));
}

void bfs(ll St) {
    queue<ll> Q;
    Q.push(St);
    dist[St][St] = 0;
    while (sz(Q)) {
        ll v = Q.front();
        Q.pop();
        for (ll u : adj[v]) {
            if (dist[St][u] > dist[St][v] + 1) {
                dist[St][u] = dist[St][v] + 1;
                Q.push(u);
            }
        }
    }
    return;
}

int main() {
    memset(dist, 63, sizeof dist);
    fast_io;
    set_random;
    cin >> n >> m >> k;
    for (ll i = 1; i <= n; i++) {
        cin >> A[i].F >> A[i].S;
    }
    for (ll i = 1; i <= m; i++) {
        cin >> C[i].F >> C[i].S.F >> C[i].S.S;
    }
    sort(C + 1, C + m + 1);
    for (ll i = 1; i <= n; i++) {
        ll par = 0;
        for (ll j = 1; j <= m && !par; j++) {
            if (Coincide(A[i], C[j])) {
                par = j;
                break;
            }
        }
        Circ[i] = par;
    }
    for (ll i = 1; i <= m; i++) {
        ll par = 0;
        for (ll j = i + 1; j <= m && !par; j++) {
            if (Coin(C[i], C[j])) {
                par = j;
                break;
            }
        }
        adj[par].push_back(i), adj[i].push_back(par);
    }
    for (ll i = 0; i <= m; i++) {
        bfs(i);
    }
    while (k--) {
        ll u, v;
        cin >> u >> v;
        cout << dist[Circ[u]][Circ[v]] << endl;
    }
    return 0;
}
