#pragma GCC optimize("O2")
#include <bits/stdc++.h>
using namespace std;

typedef long long                   ll;
typedef long double                 ld;
typedef pair<int,int>               pii;
typedef pair<ll,ll>                 pll;
typedef pair<double,double>         pdd;
typedef pair<ld,ld>                 pld;
typedef pair<string , string>       pss;

#define PB(x)                       push_back(x)
#define bs(a , x)                   binary_search(a , a + sizeof(a) / sizeof(a[0] , x)
#define ts(x)                       to_string(x)
#define jjoin(x)                    for (auto i : x) cout << i << endl;
#define all(x)                      (x).begin(),(x).end()
#define bsv(a , x)                  binary_search(all(a), x)
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define Mp                          make_pair
#define tab                         '\t'
#define sep                         ' '
#define error(x)                    cerr << #x << " = " << x << endl
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io                     freopen("in.txt" , "r+" , stdin) ; freopen("out.txt" , "w+" , stdout);
inline ll input(){ll n; cin >> n ; return n;}
ll pw(ll a , ll b)  { return (!b ? 1 : (b & 1 ? a * pw(a * a , b / 2) : pw(a * a , b / 2))); }
vector <int> adj[100005];
ll cnt[100005LL] , nex[100005LL] , u , v , tot = 0;
int main()
{
    fast_io;  /** if you sure yuor code is true but get TLE use scanf and printf*/
    int n = input();
    for (ll i = 1 ; i <= n - 1 ; i++)
    {
        cin >> u >> v;
        adj[u].PB(v);
        adj[v].PB(u);
    }
    for (ll i = 1 ;  i <= n ; i++)
    {
        cin >> nex[i];
    }
    for (ll i = 1 ; i <= n ; i++)
    {
        for (auto j : adj[i]) if (nex[i] != nex[j])
        {
            cnt[i] ++;
            cnt[j]++;
            tot++;
        }
    }
    for (ll i = 1 ; i <= n ; i++)
    {
        if (cnt[i] == tot) return cout << "YES" << endl << i , 0;
    }
    cout << "NO";
    return 0;
}
