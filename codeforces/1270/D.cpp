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
ll n, k, Pos[MAXN], A[MAXN];
vector<ll> idx;

bool cmp(ll x, ll y) {
    return A[x] < A[y];
}

void ask() {
    for (ll i = 1; i <= k + 1; i++) {
        cout << "?" << sep;
        for (ll j = 1; j <= k + 1; j++) {
            if (i == j) continue;
            cout << j << sep;
        }
        cout << endl;
        cout.flush();
        ll pos, Apos;
        cin >> pos >> Apos;
        A[i] = Apos, Pos[i] = pos;
    }
}

int main() {
    fast_io;
    set_random;
    cin >> n >> k;
    for (ll i = 1; i <= k + 1; i++) {
        idx.push_back(i);
    }
    ask();
    sort(all(idx), cmp);
    ll Cnt = 0;
    for (ll i = 0; i < k + 1; i++) {
        Cnt += (Pos[idx[i]] == Pos[idx[0]]);
    }
    cout << '!' << sep << k + 1 - Cnt << endl;
    cout.flush();
    return 0;
}
