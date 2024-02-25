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
set<ll> Rows;
ll n, q, Lava[2][MAXN], R[MAXN], C[MAXN];

int main() {
    fast_io;
    set_random;
    cin >> n >> q;
    for (ll i = 1; i <= q; i++) {
        cin >> R[i] >> C[i];
        Lava[R[i] - 1][C[i]] = 1 - Lava[R[i] - 1][C[i]];
        Rows.erase(C[i]);
        if (C[i] < n && ((Lava[0][C[i]] && Lava[1][C[i]]) ||(Lava[0][C[i]] && Lava[1][C[i] + 1]) || (Lava[1][C[i]] && Lava[0][C[i] + 1]))) Rows.insert(C[i]);
        Rows.erase(C[i] - 1);
        if (C[i] > 1 && ((Lava[0][C[i] - 1] && Lava[1][C[i] - 1]) ||(Lava[0][C[i] - 1] && Lava[1][C[i]]) || (Lava[1][C[i] - 1] && Lava[0][C[i]]))) Rows.insert(C[i] - 1);
        if (sz(Rows) || Lava[1][n]) cout << "No" << endl;
        else cout << "Yes" << endl;
    }
    return 0;
}