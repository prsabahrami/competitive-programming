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

const ll MAXN = 2e5 + 10;
const ll MAXA = 65;
const ll INF = 8e18;
const ll MOD = 998244353; //1e9 + 7
const ld PI = 4 * atan((ld) 1);
ll Row[MAXA], Col[MAXA];
char s[MAXA][MAXA];

int main() {
    fast_io;
    set_random;
    ll q;
    cin >> q;
    while (q--) {
        memset(Row, 0, sizeof(Row));
        memset(Col, 0, sizeof Col);
        ll n, m, ps = 0;
        cin >> n >> m;
        for (ll i = 1; i <= n; i++) {
            for (ll j = 1; j <= m; j++) {
                cin >> s[i][j];
                if (s[i][j] == 'A') Row[i]++, Col[j]++, ps++;

            }
        }
        if (ps == n * m) {
            cout << 0 << endl;
            continue;
        }
        if (ps == 0) {
            cout << "MORTAL" << endl;
            continue;
        }
        if (Row[1] == m || Row[n] == m || Col[1] == n || Col[m] == n) {
            cout << 1 << endl;
            continue;
        }
        if (s[1][1] == 'A' || s[1][m] == 'A' || s[n][1] == 'A' || s[n][m] == 'A') {
            cout << 2 << endl;
            continue;
        }
        bool ans = 0;
        for (ll i = 1; i <= n; i++) {
            if (Row[i] == m) {
                ans = 1;
                cout << 2 << endl;
                break;
            }
        }
        if (ans) {
            continue;
        }
        for (ll j = 1; j <= m; j++) {
            if (Col[j] == n) {
                ans = 1;
                cout << 2 << endl;
                break;
            }
        }
        if (ans) {
            continue;
        }
        if (Row[1] || Row[n] || Col[1] || Col[m]) {
            cout << 3 << endl;
            continue;
        }
        cout << 4 << endl;
    }
    return 0;
}
