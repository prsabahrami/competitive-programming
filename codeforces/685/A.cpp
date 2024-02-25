//in the name of god
//if you read this code please search about imam hussain
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pb push_back
#define endl "\n"
#define X first
#define Y second
#define pii pair<int,int>
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define read freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout)

const int maxn=1e5+5;
const int mod=1e9+7;
const int inf=1e9;
const int del=728729;

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}
ll a[30];
ll b[30];
ll c[30];
ll n;
ll m;
ll t1;
ll t2;
ll q;
ll ans;
ll nww;
ll p;
bool check(){
	q = n - 1;
    if(q == 0)
        t1 = 1;
    while(q)
    {
        q /= 7;
        t1 ++;
    }
    q = m - 1;
    if(q == 0)
        t2 = 1;
    while(q)
    {
        q /= 7;
        t2 ++;
    }
    if(t1 + t2 > 7)
    {
        return 0;
    }
    return 1;
}
void fl(){
	fill(a,a+t1,0);
    fill(b,b+t2,0);
    fill(c,c+10,0);
}
main()
{
    migmig;
    cin >> n >> m;
    if(!check()){
    	cout<<0;
    	return 0;
	}
	for(int i = 0; i < n; i++)
    	{
        for(int j = 0; j < m; j++)
        {
            fl();
            int q = i;
            bool t = 1;
            int p = 0;
            while(q)
            {
                a[p] = q % 7;
                q /= 7;
                p ++;
            }
            q = j;
            p = 0;
            while(q)
            {
                b[p] = q % 7;
                q /= 7;
                p ++;
            }
 
            for(int k = 0; k < t1; k++)
            {
                if(c[a[k]])
                    t = 0;
                c[a[k]] = 1;
            }
            for(int k = 0; k < t2; k++)
            {
                if(c[b[k]])
                    t = 0;
                c[b[k]] = 1;
            }
            ans += t;
        }
    }
    cout << ans;
 
 
}
