#pragma GCC optimize("O2")
#include <bits/stdc++.h>
using namespace std;

typedef long long int               ll;
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
#define set_random                  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
inline ll input(){ll n; cin >> n ; return n;}
ll pw(ll a , ll b)  { return (!b ? 1 : (b & 1 ? a * pw(a * a , b / 2) : pw(a * a , b / 2))); }
const ll MAXN = 1e5 + 10;
ll dp[MAXN][2];
ll a[MAXN] , b[MAXN];
int main()
{
    fast_io;  /** if you sure yuor code is true but get TLE use scanf and printf*/
    //file_io;
    set_random;
    ll n;
    cin >> n;
    for (ll i = 0 ; i < n ; i++)
    {
        cin >> a[i];
    }
    for (ll i = 0 ; i < n ; i++)
    {
        cin >> b[i];
    }
    dp[0][0] = a[0];
    dp[0][1] = b[0];
    dp[1][0] = dp[0][1] + a[1];
    dp[1][1] = dp[0][0] + b[1];
    for (ll i = 1 ; i < n ; i++)
    {
        dp[i][0] = max(dp[i - 1][1] + a[i] , dp[i - 2][1] + a[i]);
        dp[i][1] = max(dp[i - 1][0] , dp[i - 2][0]) + b[i];

    }
    cout << max(dp[n - 1][0] , dp[n - 1][1]) << endl;
    return 0;
}
