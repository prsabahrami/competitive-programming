#include<bits/stdc++.h>
using namespace::std;

#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;

vector<int> adj[maxn];

bool hide[maxn];

int res[maxn] , sz[maxn];

void plant(int v , int p = -1)
{
  	sz[v] = 1;
  	for(auto u : adj[v])
      	if(u != p && !hide[u])
        {
          	plant(u , v);
          	sz[v] += sz[u];
        }
}

int find_centroid(int v , int n , int p = -1)
{
  	for(auto u : adj[v])
      	if(u != p && !hide[u] && sz[u] * 2 > n)
          	return find_centroid(u , n , v);
  	return v;
}

void solve(int v , int h = 0)
{
	plant(v);
	v = find_centroid(v , sz[v]);
  
  	hide[v] = 1;
  	res[v] = h;
  	for(auto u : adj[v])
      	if(!hide[u])
          	solve(u , h + 1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for(int i = 0; i < n - 1; i++)
	{
		int a , b;
		cin >> a >> b;
		a-- , b--;

		adj[a].pb(b);
		adj[b].pb(a);
	}

	solve(0);
  	
  	for(int i = 0; i < n; i++)
      	cout << (char)('A' + res[i]) << " ";
  	cout << endl;
}

