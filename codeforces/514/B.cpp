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
const ll MAXN = 2e5 + 10;
ld a[MAXN];
ll j = 0 , c = 0 , d = 0 , e = 0 , n , res = 0;
ld x , y , x1 , y1;
int main()
{

   cin >> n >> x >> y;

   for(ll i = 0 ; i < n ; i++)
   {
       cin >> x1 >> y1;
       if(x == x1)
       c++;
       else if (y == y1)
       e++;
       else
       {
       a[j] = (y - y1) / (x - x1);
       j++;
       }
   }

   n = n - c - e;
//cout << j << endl;
   if(c > 0)
   d++;
   if(e > 0)
   d++;
   sort(a ,a + n);
   for(ll i = 0 ; i < n ; i++)
   {
       res++;
       for(j = i ; j < n ; j++)
       {
           //cout << j << " ";
           if(a[j] != a[i])
          {
              break;
          }
       }
       i = j - 1;
       //cout << i << endl;

   }
   cout << d + res << endl;
    return 0;
}