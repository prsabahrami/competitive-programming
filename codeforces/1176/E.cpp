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
int visited[200452];

void build(int a){
    for(int i = 0; i < a+10; i++)
        visited[i] = 0;
}

void dfs(int v, int cor, vector<int> adj[]){
    visited[v] = cor;
    for(int i = 0; i < adj[v].size(); i++){
        if(visited[adj[v][i]] == 0){
            dfs(adj[v][i], -cor, adj);
        }
    }
}


int main(){
    fast_io;
    set_random;
    int n , t;
    cin >> t;
    for(int i = 0; i < t ; i++){
        int v, e;
        cin >> v >> e;
        vector<int> adj[v + 1];
        build(v);
        for(int k = 0 ; k < e ; k++){
            int a , b;
            cin >> a >> b;
            adj[a].PB(b);
            adj[b].PB(a);
        }
        dfs(1, 1, adj);

        int cont = 0;
        for(int k = 0 ; k < v + 1 ; k++)
            cont += visited[k];

        if(cont > 0){
            vector<int> a;
            for(int i = 0 ; i < v + 1 ; i++){
                if(visited[i] < 0){
                    a.PB(i);
                }
            }
            cout << a.size() << endl;
            for(int i = 0; i < a.size() ; i++ )
                cout << a[i] << sep;
            cout << endl;
        }
        else{
            vector<int> a;
            for(int i = 0; i < v + 1 ; i++){
                if(visited[i] > 0){
                    a.PB(i);
                }
            }
            cout << a.size() << endl;
            for(int i = 0;  i < a.size() ;i++ )
                cout << a[i] << sep;
            cout << endl;
        }

    }
    return 0;
}
