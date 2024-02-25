/* mashtali dahanet servis */
#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
 
#define SZ(x)                       (int) x.size()
#define F                           first
#define S                           second

const int N = 5e5 + 10, MOD = 1e9 + 7;
int D[N], C[N], n; char S[N]; vector<int> adj[N];

void clr() {
    for (int i = 1; i <= n; i++)
        adj[i] = {}, C[i] = D[i] = 0;
}

int main() {
    int t;
    for (scanf("%d", &t); t; t--) {
        scanf("%d", &n);
        for (int i = 1; i < n; i++) {
            int u, v; scanf("%d%d", &u, &v);
            adj[u].push_back(v); D[v]++;
            adj[v].push_back(u); D[u]++;
        }
        scanf("%s", S + 1); int f = 0;
        for (int i = 1; i <= n; i++) f |= (D[i] > 3);
        if (f) { clr(), printf("White\n"); continue; }
        for (int i = 1; i <= n; i++) {
            f += (D[i] > 2);
            C[i] = (S[i] != 'W' ? 0 : 1);
        }
        for (int i = 1; i <= n; i++) {
            if (D[i] > 2) {
                int w = 0, b = C[i];
                for (int j : adj[i]) 
                    w += (D[j] > 1), b |= C[j];
                if (w > 1 || b) f = MOD;
            }
        }
        if (f > 2) { clr(), printf("White\n"); continue; }
        if (f < 1) {
            f = 0; int c = 0;
            for (int i = 1; i <= n; i++) {
                f |= (SZ(adj[i]) > 1 && C[i] && n > 3), c += C[i];
            }
            if (n == 3) {
                int c2 = (C[1] + C[2] + C[3]);
                if (c2 == 2) f = 1;
            }
            if (c == 2 && n % 2) f = 1;
            if (f) { clr(), printf("White\n"); continue; }
            clr(), printf("Draw\n");
        } else if (f < 2) {
            f = 0; int c = 0;
            for (int i = 1; i <= n; i++) 
                f |= (D[i] > 1 && C[i]), c += C[i];
            if (c && n % 2 == 0) f = 1;
            if (f) { clr(), printf("White\n"); continue; }
            clr(); printf("Draw\n"); 
        } else {
            f = (n & 1);
            for (int i = 1; i <= n; i++) 
                f |= C[i];
            if (f) { clr(), printf("White\n"); continue; }
            clr(), printf("Draw\n");
        }
    }
    return 0;
}

