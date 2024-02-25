#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;
 
#define SZ(x)                       (ll) x.size()
#define F                           first
#define S                           second

const ll N = 100 + 10, MOD = 1e9 + 7;
template<class T , ll SZ>

struct Mat {
    ll n, m;
    T mat[SZ][SZ];

    Mat(ll _n , ll _m) {
        n = _n;
        m = _m;
        Fill(0);
    }

    void Fill(T x) {
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < m; j++) {
                mat[i][j] = x;
            }
        }
    }

    friend Mat operator*(const Mat &x ,const Mat &y) {
        assert(x.m == y.n);
        Mat ans = Mat(x.n , y.m);
        for (ll i = 0; i < x.n; i++) {
            for (ll j = 0; j < y.m; j++) {
                for (ll k = 0; k < x.m; k++) {
                    ans.mat[i][j] += (x.mat[i][k] * y.mat[k][j]) % MOD;
                    ans.mat[i][j] %= MOD;
                }
            }
        }
        return ans;
    }

    friend Mat operator^(Mat t , ll x) {
        assert(t.n == t.m);
        Mat ans = Mat(t.n , t.m);
        for(ll i = 0 ; i < t.n ; i++)   ans.mat[i][i] = 1;
        while (x != 0) {
            if (x % 2 == 1) ans = ans * t;
            x >>= 1;
            t = t * t;
        }
        return ans;
    }
};
ll A[N], B[N], C[N], n, k;

int main() {
	scanf("%lld%lld", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%lld%lld%lld", &A[i], &B[i], &C[i]);
	}
	Mat<ll, 20> M(16, 16), DP(16, 1); DP.mat[15][0] = 1;
	for (int i = 1; i <= n; i++) {
		M.Fill(0);
		if (!C[i]) M.mat[15][15] = 1;
		else {
			M.mat[15][15] = M.mat[15][14] = 1;
			for (int j = 1; j < C[i]; j++) {
				M.mat[15 - j][15 - j + 1] = M.mat[15 - j][15 - j] = M.mat[15 - j][15 - j - 1] = 1;
			}
			M.mat[15 - C[i]][15 - C[i] + 1] = M.mat[15 - C[i]][15 - C[i]] = 1;
		}
		if (i == n) DP = (M ^ (k - A[i])) * DP;
		else DP = (M ^ (B[i] - A[i])) * DP;
		//printf("%lld\n", DP.mat[15][0]);
	}
	printf("%lld\n", DP.mat[15][0]);
    return 0;
}

