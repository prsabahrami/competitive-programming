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

const ll MAXN = 1e9 + 10;
const ll MAXA = 101;
const ll INF = 8e18;
const ll MOD = 998244353; //1e9 + 7
const ld PI = 4 * atan((ld) 1);
ll q;

template<ll SZ>
struct BITree {
    map<ll, map<ll, ll>> fen;

    void update(ll ind, ll val, ll idx) {
        for (; ind < SZ; ind += (ind & (-ind))) fen[idx][ind] += val;
    }

    ll get(ll x, ll idx) {
        ll sum = 0;
        for (; x; x -= (x & (-x))) sum += fen[idx][x];
        return sum;
    }
};

BITree<MAXN> fen;

int main() {
    fast_io;
    set_random;
    cin >> q;
    while (q--) {
        ll Q, t, x;
        cin >> Q >> t >> x;
        if (Q == 1) fen.update(t, 1, x);
        else if (Q == 2) fen.update(t, -1, x);
        else cout << fen.get(t, x) << endl;

    }
    return 0;
}
