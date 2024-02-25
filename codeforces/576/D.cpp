#include <bits/stdc++.h>
#pragma GCC optimize("O2")

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;
 
#define SZ(x)                       (ll) x.size()
#define F                           first
#define S                           second

const ll N = 150 + 10, INF = 8e18;
ll D[N], dist[N], R = INF; int n, m, id[N];
pair<int, int> E[N]; vector<int> adj[N];

template<class T, int SZ>
struct Mat {
    int n, m;
    T mat[SZ];

    Mat(int _n , int _m) {
        n = _n;
        m = _m;
        Fill(0);
    }

    void Fill(int x) {
    	for (int i = 0; i < n; i++) {
    		for (int j = 0; j < m; j++) {
    			mat[i][j] = x;
    		}
    	}
    }

    friend Mat operator*(const Mat &x, const Mat &y) {
        assert(x.m == y.n);
        Mat ans = Mat(x.n , y.m);
        for (int i = 0; i < x.n; i++) {
            for (int j = 0; j < y.m; j++) {
               	if (x.mat[i][j]) ans.mat[i] |= y.mat[j];
            }
        }
        return ans;
    }

    friend Mat operator^(Mat t, ll x) {
        assert(t.n == t.m);
        Mat ans = Mat(t.n, t.m);
        for (int i = 0; i < t.n; i++) ans.mat[i][i] = 1;
        while (x != 0) {
            if (x & 1) ans = ans * t;
            x >>= 1;
            t = t * t;
        }
        return ans;
    }
};

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%lld", &E[i].F, &E[i].S, &D[i]);
		id[i] = i;
	}
	sort(id + 1, id + m + 1, [&] (int x, int y) {
		return D[x] < D[y];
	});
	Mat<bitset<N>, N> A(n, n), B(n, n); B.mat[0][0] = 1;
	for (int i = 1; i <= m; i++) {
		B = B * (A ^ (D[id[i]] - D[id[i - 1]]));
		A.mat[E[id[i]].F - 1][E[id[i]].S - 1] = 1;
		adj[E[id[i]].S - 1].push_back(E[id[i]].F - 1);
		fill(dist, dist + N, INF);
		queue<int> q; q.push(n - 1); dist[n - 1] = 0;
		while (SZ(q)) {
			int v = q.front(); q.pop();
			if (B.mat[0][v]) R = min(R, D[id[i]] + dist[v]);
			for (int u : adj[v]) {
				if (dist[u] > dist[v] + 1) {
					dist[u] = dist[v] + 1;
					q.push(u);
				}
			}
		}
	}
	if (R != INF) printf("%lld\n", R);
	else printf("Impossible");
    return 0;
}
 