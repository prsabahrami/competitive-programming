/* I do it for the glory */
#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
 
#define SZ(x)                       (int) x.size()
#define F                           first
#define S                           second

const int MOD = 1e9 + 7;

void nima(int &x, int md = MOD) {
    if (x >= md) x -= md;
    if (x < 0) x += md;
}

template<int N = 50> struct Matrix {
    int n, m, M[N][N];

    Matrix(int _n = 0, int _m = 0, int x = 0) : n(_n), m(_m) { 
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < m; j++) 
                M[i][j] = x * (i == j);
    }

    int* operator[](int i) { return M[i]; }

    friend Matrix operator*(Matrix A, Matrix B) {
        assert(A.m == B.n);
        Matrix<N> C(A.n, B.m);
        for (int i = 0; i < A.n; i++) 
            for (int k = 0; k < A.m; k++) 
                for (int j = 0; j < B.m; j++) 
                    nima(C[i][j] += 1ll * A[i][k] * B[k][j] % MOD);
        return C;
    }

    void print() {
        for (int i = 0; i < n; i++, printf("\n")) 
            for (int j = 0; j < m; j++) 
                printf("%d ", M[i][j]);
    }
};
ll n; int k, X; 

Matrix<> S(Matrix<> &A, int x) {
    Matrix<> ret(k + 1, k + 1);
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) 
            ret[(i + x) % k][(j + x) % k] = A[i][j];
        ret[(i + x) % k][k] = A[i][k];
    }
    for (int i = 0; i <= k; i++) 
        ret[k][i] = A[k][i];
    return ret;
}

int main() {
    scanf("%lld%d", &n, &k);
    vector<int> D;
    for (; n; n /= k) 
        D.push_back(n % k), X += n % k;
    Matrix<> ret(k + 1, 1), M(k + 1, k + 1, 1); 
    ret[k][0] = 1;
    for (int i = 0; i < k + 1; i++) 
        M[0][i] = 1;
    for (int i = 0; i < SZ(D); i++) {
        nima(X -= D[i], k);
        for (int j = D[i] - 1; ~j; j--) ret = S(M, (j + X) % k) * ret;
        Matrix<> nM(k + 1, k + 1, 1);
        for (int j = 0; j < k; j++) 
            nM = nM * S(M, j);
        swap(M, nM);
    }
    int ans = 0;
    for (int i = 0; i < k + 1; i++) 
        nima(ans += ret[i][0]);
    printf("%d\n", ans);
    return 0;
}

