/* I do it for the glory */
#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
 
#define SZ(x) (int) x.size()
#define F first
#define S second

const int N = 1e6 + 10, MOD = 1e9 + 7;
int t, n, m, A[N], C[N], M[N]; vector<int> ret;

int check(int x) {
    fill(M, M + n, 0);
    int c = 0;
    for (int i = 0; i < n; i++) {
        if (!M[i]) {
            c++;
            int v = i;
            while (!M[v]) M[v] = 1, v = (A[v] + x) % n;
        }
    }
    return n - c <= m;
}

int main() {
    for (scanf("%d", &t); t; t--) {
        scanf("%d%d", &n, &m); ret = {};
        for (int i = 0; i < n; i++) 
            scanf("%d", &A[i]), A[i]--, C[i] = 0;
        for (int i = 0; i < n; i++) {
            C[(i - A[i] + n) % n]++;
        }
        for (int i = 0; i < n; i++) {
            if (C[i] * 3 >= n && check(i)) ret.push_back(i);
        }
        printf("%d ", SZ(ret));
        for (int &x : ret) printf("%d ", x);
        printf("\n");
    }
    return 0;
}

