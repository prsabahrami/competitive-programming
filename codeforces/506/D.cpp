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

const ll MAXN = 2e6 + 10;
const ll MAXA = 101;
const ll INF = 8e18;
const ll MOD = 998244353; //1e9 + 7
const ld PI = 4 * atan((ld) 1);
vector<ll> Col[MAXN];
map<pll, ll> Asked;
ll q, n, m;

template<ll SIZE>
struct DSU {
    unordered_map<ll, ll> par[MAXN];

    ll Find(ll col, ll v) {
        return par[col].find(v) == par[col].end() ? v : par[col][v] = Find(col, par[col][v]);
    }

    ll Union(ll col, ll u, ll v) {
        ll pu = Find(col, u), pv = Find(col, v);
        if (pu == pv) return 0;
        par[col][pv] = pu;
        return 1;
    }

    bool SameComp(ll col, ll v, ll u) {
        return Find(col, u) == Find(col, v);
    }

};

DSU<MAXN> dsu;

int main() {
    //fast_io;
    set_random;
    scanf("%lld%lld", &n, &m);
    for (ll i = 1; i <= m; i++) {
        ll u, v, col;
        scanf("%lld%lld%lld", &u, &v, &col);
        Col[u].emplace_back(col);
        Col[v].emplace_back(col);
        dsu.Union(col, u, v);
    }
    for (ll i = 1; i <= n; i++) {
        sort(all(Col[i]));
        Col[i].resize(unique(all(Col[i])) - Col[i].begin());
    }
    scanf("%lld", &q);
    while (q--) {
        ll u, v, cnt = 0;
        scanf("%lld%lld", &u, &v);
        if (sz(Col[u]) > sz(Col[v]))
            swap(u, v);
        if (Asked.find({u, v}) != Asked.end()) {
            printf("%ld\n", Asked[{u, v}]);
        } else {
            for (ll col : Col[u]) {
                cnt += dsu.SameComp(col, u, v);
            }
            Asked[{u, v}] = cnt;
            printf("%ld\n", cnt);
        }
    }
    return 0;
}
