/* I do it for the glory */
#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
 
#define SZ(x)                       (int) x.size()
#define F                           first
#define S                           second

const int N = 1e6 + 10, MOD = 1e9 + 7;
int n, A[N], lst[N], M[N]; vector<int> adj[N], C[2];

void AghaNima_2() {
    printf("First\n");
    fflush(stdout);
    for (int i = 1; i <= 2 * n; i++) {
        printf("%d ", i > n ? i - n : i);
    }
    fflush(stdout);
}

void DFS(int v, int c = 0) {
    M[v] = 1, C[c].push_back(v);
    for (int &u : adj[v]) 
        if (!M[u]) DFS(u, c ^ 1);
}

void AghaNima_1() {
    printf("Second\n");
    fflush(stdout);
    for (int i = 1; i <= 2 * n; i++) {
        scanf("%d", &A[i]);
        if (lst[A[i]]) adj[i].push_back(lst[A[i]]), adj[lst[A[i]]].push_back(i);
        else lst[A[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        adj[i].push_back(n + i);
        adj[n + i].push_back(i);
    }
    for (int i = 1; i <= n; i++) 
        if (!M[i]) DFS(i);
    ll S = 0;
    for (int &v : C[0]) 
        S += v;
    if (S % (2 * n)) {
        for (int &v : C[1]) printf("%d ", v);
        printf("\n");
        fflush(stdout);
    } else {
        for (int &v : C[0]) 
            printf("%d ", v);
        printf("\n");
        fflush(stdout);
    }
}

int main() {
    scanf("%d", &n);
    if (n & 1) AghaNima_1();
    else AghaNima_2();
    return 0;
}

