/* Just a drop of water in an endless sea */
#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
 
#define SZ(x) (int) x.size()
#define F first
#define S second

const int N = 100, MOD = 1e9 + 7;
int t, n; char S[N], ret[N][N];

int main() {
    scanf("%d", &t);
    for (; t; t--) {
        scanf("%d", &n);
        scanf("%s", S + 1);
        vector<int> X;
        for (int i = 1; i <= n; i++) 
            if (S[i] == '1') X.push_back(i);
        if (SZ(X) == n - 1 || SZ(X) == n - 2) { printf("NO\n"); continue; }
        for (int v : X) {
            for (int i = 1; i <= n; i++) {
                if (v == i) ret[i][i] = 'X';
                else ret[v][i] = ret[i][v] = '=';
            }
        }
        X = {};
        for (int i = 1; i <= n; i++) if (S[i] == '2') X.push_back(i);
        for (int i = 0; i + 1 < SZ(X); i++) 
            ret[X[i]][X[i + 1]] = '+', ret[X[i + 1]][X[i]] = '-';
        if (SZ(X)) ret[X.back()][X[0]] = '+', ret[X[0]][X.back()] = '-';
        for (int i = 0; i < SZ(X); i++) 
            for (int j = 0; j < SZ(X); j++) {
                if (i == j) ret[X[i]][X[j]] = 'X';
                else if (SZ(X) && (i + 1) % SZ(X) != j && (j + 1) % SZ(X) != i) ret[X[i]][X[j]] = '=';
            }
        printf("YES\n");
        for (int i = 1; i <= n; i++, printf("\n")) 
            for (int j = 1; j <= n; j++) printf("%c", ret[i][j]);
    }
    return 0;
}

