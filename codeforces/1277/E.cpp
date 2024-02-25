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
ll n, m, A, B, Par[MAXN];
map<pll , ll> Count;
template<ll SIZE>
struct DSU {
    ll par[SIZE], SZ[SIZE];

    void Fill(ll sZ) {
        fill(par, par + sZ, -1), fill(SZ, SZ + sZ, 1);
    }

    ll Find(ll v) {
        return (par[v] == -1 ? v : par[v] = Find(par[v]));
    }

    ll Union(ll v, ll u) {
        ll pv = Find(v), pu = Find(u);
        if (pv == pu) return 0;
        if (SZ[pv] < SZ[pu]) swap(pu, pv);
        par[pu] = pv;
        SZ[pv] += SZ[pu];
        return 1;
    }

    ll getSize(ll v) {
        return SZ[Find(v)];
    }
};

DSU<MAXN> dsu;

ll C2(ll x) {
    return x * (x - 1) / 2;
}

int main() {
    fast_io;
    set_random;
    ll q;
    cin >> q;
    while (q--) {
        vector<pll> Edge;
        cin >> n >> m >> A >> B;
        ll cnt = C2(n);
        //cout << "BIB: " << cnt << endl;
        for (ll i = 1; i <= m; i++) {
            ll u, v;
            cin >> u >> v;
            Edge.emplace_back(u, v);
        }
        dsu.Fill(n + 20);
        for (auto edge : Edge) {
            if (edge.S == A || edge.F == A) continue;
            dsu.Union(edge.S, edge.F);
        }
        for (ll i = 1; i <= n; i++) {
            if (i == dsu.Find(i)) cnt -= C2(dsu.getSize(i)); //cout << "BIBBB" << sep << cnt << endl;
            Par[i] = dsu.Find(i);
        }
        cnt -= n - dsu.getSize(B);
        dsu.Fill(n + 20);
        //cout << dsu.getSize(B) << sep << "CHECK" << endl;
        for (auto edge : Edge) {
            if (edge.S == B || edge.F == B) continue;
            dsu.Union(edge.S, edge.F);
        }
        cnt -= n - dsu.getSize(A) - 1;

        Count.clear();
        for (ll i = 1; i <= n; i++) {
            Count[{dsu.Find(i), Par[i]}]++;
            if (dsu.Find(i) == i) cnt -= C2(dsu.getSize(i));
        }
        for (auto x : Count) {
            cnt += C2(x.S);
        }
        cout << cnt << endl;
        // OMG i am getting FUCKED UPPPPPPPP!!!!
    }
    return 0;
}

