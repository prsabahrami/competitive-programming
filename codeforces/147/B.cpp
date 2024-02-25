#include <bits/stdc++.h>
#pragma GCC optimize("O2") 
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;
 
#define SZ(x)                       (ll) x.size()
#define F                           first
#define S                           second

const ll N = 300 + 10, INF = 1e18, LOG = 15;
template<class T, int SZ>
struct Mat {
    int n, m;
    T mat[SZ][SZ];
 
    Mat(int _n , int _m) {
        n = _n;
        m = _m;
        Fill(-INF);
    }
 
    void Fill(T x) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == j) mat[i][j] = 0;
                else mat[i][j] = x;
            }
        }
    }
 
    friend Mat operator+(const Mat &x ,const Mat &y) {
        assert(x.m == y.n);
        Mat ans = Mat(x.n , y.m);
        for (int i = 0; i < x.n; i++) {
            for (int j = 0; j < y.m; j++) {
                for (int k = 0; k < x.m; k++) {
                    ans.mat[i][j] = max(ans.mat[i][j], x.mat[i][k] + y.mat[k][j]);
                }
            }
        }
        return ans;
    }
 
    friend Mat operator^(Mat t, ll x) {
        assert(t.n == t.m);
        Mat ans = Mat(t.n , t.m);
        for (int i = 0; i < t.n; i++)	ans.mat[i][i] = 1;
        while (x != 0) {
            if (x & 1) ans = ans * t;
            x >>= 1;
            t = t * t;
        }
        return ans;
    }
};
int n, m, C[2][N * N], E[2][N * N];
vector<Mat<ll, N>> dp;

int check(Mat<ll, N> M) {
	for (int i = 0; i < n; i++) {
		if (M.mat[i][i] > 0) return 1;
	}
	return 0;
}

int main() {
	scanf("%d%d", &n, &m);
	for (ll i = 0; i < LOG; i++) dp.push_back(Mat<ll, N> (n, n));
	for (int i = 1; i <= m; i++) {
		int u, v, wi, wj; scanf("%d%d%d%d", &u, &v, &wi, &wj);
		u--, v--;
		dp[0].mat[u][v] = wi, dp[0].mat[v][u] = wj;
	}
	for (ll i = 1; i < LOG; i++) {
		dp[i] = dp[i - 1] + dp[i - 1];
	}
	Mat<ll, N> A(n, n), T(n, n); int ans = 0, lst = -1;
	for (int i = LOG - 1; i >= 0; i--) {
		if (lst == -1) T = dp[i], lst = 0;
		else T = A + dp[i];
		if (!check(T)) {
			A = T;
			ans ^= (1 << i);
		}
	}
	if (ans > n) printf("0\n");
	else printf("%d\n", ans + 1);
    return 0;
}

