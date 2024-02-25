/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author parsa bahrami
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

const ll MAXN = 1e6 + 10;
const ll MAXA = 101;
const ll INF = 8e18;
const ll MOD = 998244353; //1e9 + 7
const ld PI = 4 * atan((ld) 1);
vector<ll> Tour;
vector<pll> adj[MAXN];
ll n, m, last = -1, Turn = 0, Pointer[MAXN], mark[MAXN];

void EulerianTour(ll v) {
    while (Pointer[v] < sz(adj[v])) {
        ll u = adj[v][Pointer[v]].F, ind = adj[v][Pointer[v]++].S;
        if (!mark[ind]) {
            mark[ind] = 1;
            EulerianTour(u);
        }
    }
    Tour.push_back(v);
}

int main() {
    fast_io;
    set_random;
    cin >> n >> m;
    for (ll i = 1; i <= m; i++) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back({v, i}), adj[v].push_back({u, i});
    }

    for (ll i = 1; i <= n; i++) {
        if (sz(adj[i]) & 1) {
            if (Turn) {
                m++;
                adj[last].push_back({i, m}), adj[i].push_back({last, m});
                Turn ^= 1;
            } else Turn ^= 1, last = i;
        }
    }
    if (m & 1) adj[1].push_back({1, ++m});
    EulerianTour(1);
    cout << m << endl;
    for (ll i = 0; i < sz(Tour) - 1; i += 2) {
        cout << Tour[i] << sep << Tour[i + 1] << endl;
        cout << Tour[i + 2] << sep << Tour[i + 1] << endl;
    }
    return 0;
}