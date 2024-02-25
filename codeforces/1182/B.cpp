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
int main() {
    int h, w;
    int c1 = 0, c2 = 0;
    cin >> h >> w;
    char colors [h][w];
    bool used [h][w];
    bool exist = false;
    for (int i = 0; i < h ; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> colors[i][j];
            used[i][j] = false;
            if (colors[i][j] == '*')
            {
                c1 += 1;
            }
        }
    }

    int x, y;

    for (int i = 1; i < h - 1 ; i++)
    {
        for (int j = 1; j < w - 1 ; j++)
        {
            if (colors[i][j] == '*')
            {
                if (colors[i - 1][j] == '*' && colors[i + 1][j] == '*' && colors[i][j - 1] == '*' && colors[i][j + 1] == '*')
                {
                    exist = true;
                    used[i][j] = true;
                    c2 += 1;
                    x = j;
                    y = i;
                    break;
                }
            }
        }
    }

    if (exist)
    {
        int a;

        a = y - 1;
        while (a >= 0 && a < h && colors[a][x] != '.')
        {
            used[a][x] = true;
            c2 += 1;
            a--;
        }
        a = y + 1;
        while (a >= 0 && a < h && colors[a][x] != '.')
        {
            used[a][x] = true;
            c2 += 1;
            a++;
        }

        a = x - 1;
        while (a >= 0 && a < w && colors[y][a] != '.')
        {
            used[y][a] = true;
            c2 += 1;
            a--;
        }
        a = x + 1;
        while (a >= 0 && a < w && colors[y][a] != '.')
        {
            used[y][a] = true;
            c2 += 1;
            a++;
        }
    }

    if (c1 == c2 && exist)
    {
        cout << "YES" << endl;
    } else
    {
        cout << "NO" << endl;
    }

    return 0;
}
