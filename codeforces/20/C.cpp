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
const ll MAXN = 1e6 + 5 , INF = 1e18;
int n, m, pr[MAXN];
ll dist[MAXN];
vector<pair<int, int> > g[MAXN];
priority_queue<pair<int, ll > > pq;
void f(int v)
{
    if(pr[v])
		f(pr[v]);

    cout << v << sep;
}

int main()
{
    n = input() , m = input();
    fill_n(dist + 1 , MAXN, INF);

    for(int i = 0; i < m ; i++)
    {
		ll v = input() , u = input() , w = input();
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}

    pq.push({dist[1] = 0, 1});
    while(!pq.empty())
    {
        int u = pq.top().second; pq.pop();

        for(auto p : g[u])
        {
			if(dist[u] + p.second < dist[p.first])
			{
				dist[p.first] = dist[u] + p.second;
				pq.push({-dist[p.first], p.first});
				pr[p.first] = u;
			}
		}
    }

    if(dist[n] == INF) cout << -1 << endl;
    else f(n);
}
