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

const ll MAXN = 2e6 + 10;
const ll MAXA = 101;
const ll INF = 8e18;
const ll MOD = 998244353; //1e9 + 7
const ld PI = 4 * atan((ld) 1);
ll dp[3][MAXN], A[MAXN], n;

int main() {
    fast_io;
    set_random;
    cin >> n;
    for (ll i = 1; i <= n; i++) {
        cin >> A[i];
        if (i == 1) {
            A[0] = A[i];
        }
    }

    for (ll i = 1; i <= n; i++) {
        dp[1][i] = dp[0][i] = max(dp[1][i - 1], dp[0][i - 1]);
        if (A[i] >= A[i - 1])
            dp[1][i] = max(dp[1][i], dp[1][i - 1] + A[i] - A[i - 1]);
        if (A[i] <= A[i - 1])
            dp[0][i] = max(dp[0][i], dp[0][i - 1] + A[i - 1] - A[i]);
    }

    cout << max(dp[0][n], dp[1][n]) << endl;
    return 0;
}