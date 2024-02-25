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
#define set_random                  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
inline ll input(){ll n; cin >> n ; return n;}
ll pw(ll a , ll b)  { return (!b ? 1 : (b & 1 ? a * pw(a * a , b / 2) : pw(a * a , b / 2))); }
const ll MAXN = 1e6 + 10 , INF = 1e18 + 5;
ll cnt[MAXN] , mini[MAXN] , maxi[MAXN] , n , inp[MAXN] , ansf , anss , maxn = 0;

int main()
{
    fast_io;  /** if you sure yuor code is true but get TLE use scanf and printf*/
    n = input();
    fill(mini , mini + MAXN , INF);
    for (ll i = 0 ; i < n ; i++)
    {
        cin >> inp[i];
        cnt[inp[i]]++;
        mini[inp[i]] = min(mini[inp[i]] , i);
        maxi[inp[i]] = i;
    }
    for (ll i = 0 ; i < MAXN ; i++)
    {
        if (cnt[i] > maxn)
        {
            ansf = maxi[i];
            anss = mini[i];
            maxn = cnt[i];
        }
        if (cnt[i] == maxn && ansf - anss > maxi[i] - mini[i])
        {
            ansf = maxi[i];
            anss = mini[i];
        }
    }
    cout << anss + 1 << sep << ansf + 1<< endl;
    return 0;
}
