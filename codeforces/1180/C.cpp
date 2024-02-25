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
vector <pll> p;
deque <ll> dq;
ll a[MAXN];
int main()
{
    fast_io;
    ll n = input() , q = input() , m , maxi = -1;


    for(ll i = 0 ; i < n ; i++)
    {
        a[i] = input();
        maxi = max(maxi , a[i]);
        dq.push_back(a[i]);
    }
    while(dq.front() != maxi)
    {
        ll u = dq.front(); dq.pop_front();
        ll v = dq.front(); dq.pop_front();
        p.push_back({u,v});
        dq.push_front(max(u,v));
        dq.push_back(min(u,v));
        // cout<<"yes\n";
    }
    ll ind = 0;
    while(!dq.empty())
    {
        a[ind] = dq.front();
        dq.pop_front();
        ind++;
    }
    while(q--)
    {
        m = input();
        if(m <= (ll)p.size()) cout<< p[m - 1].first << sep << p[m - 1].second << endl;
        else
        {
            ll x = (m - (ll)p.size() - 1) % (n - 1);
            cout << maxi << sep << a[x + 1] << endl;
        }

    }

    return 0;
}
