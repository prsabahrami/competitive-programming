#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;
 
#define SZ(x)                       (ll) x.size()
#define F                           first
#define S                           second

const ll N = 3e3 + 10, MOD = 12345;

template<class T , ll SZ>
struct Mat {
    int n, m;
    T mat[SZ][SZ];
 
    Mat(int _n , int _m) {
        n = _n;
        m = _m;
        Fill(0);
    }
 
    void Fill(T x) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                mat[i][j] = x;
            }
        }
    }
 
    friend Mat operator*(const Mat &x ,const Mat &y) {
        assert(x.m == y.n);
        Mat ans = Mat(x.n , y.m);
        for (int i = 0; i < x.n; i++) {
            for (int j = 0; j < y.m; j++) {
                for (int k = 0; k < x.m; k++) {
                    ans.mat[i][j] += x.mat[i][k] * y.mat[k][j];
                    if ((k & 7) == 0) ans.mat[i][j] %= MOD;
                }
                ans.mat[i][j] %= MOD;
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

map<vector<int>, int> mp; Mat<ll, 200> B(150, 150);
vector<int> vec(30, 0); int f[30], M[N], A[N], Q[N], m, timer = 1; ll n, R;

void generate(ll pos = 1) {
	if (pos == 27) {
		mp[vec] = timer++;
	} else {
		for (int i = 0; i < max(1, M[pos]); i++) {
			vec[pos] = i;
			generate(pos + 1);
		}
	}
}

void add_edge(int pos = 1) {
	if (pos == 27) {
		for (int i = 1; i < pos; i++) {
			if (!M[i]) continue;
			int t = vec[i], x = mp[vec];
			vec[i] = (vec[i] + 1) % M[i];
			B.mat[x][mp[vec]]++;
			vec[i] = t;
		}
	} else {
		for (int i = 0; i < max(1, M[pos]); i++) {
			vec[pos] = i;
			add_edge(pos + 1);
		}
	}
}

int check() {
	fill(f, f + 30, 0);
	for (int i = 1; i <= m; i++) {
		if ((vec[Q[i]] % A[i]) == 0) f[Q[i]] = 1;
	}
	for (int i = 1; i <= 26; i++) if (M[i] && !f[i]) return 0;
	return 1;
}

void answer(int pos = 1) {
	if (pos == 27) {
		if (check()) R = (R + B.mat[1][mp[vec]]) % MOD;
	} else {
		for (int i = 0; i < max(1, M[pos]); i++) {
			vec[pos] = i;
			answer(pos + 1);
		}
	}
}

int main() {
	scanf("%lld%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		char c; cin >> c; int x; scanf("%d", &x);
		if (!M[c - 'A' + 1]) M[c - 'A' + 1] = 1;
		M[c - 'A' + 1] *= x; Q[i] = c - 'A' + 1, A[i] = x;
	}
	generate();
	add_edge();
	B = B ^ n;
	answer();
	printf("%lld\n", R);
    return 0;
}

