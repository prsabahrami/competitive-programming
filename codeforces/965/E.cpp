#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
 
#define SZ(x)                       (int) x.size()
#define F                           first
#define S                           second

const int N = 1e5 + 10;
int trie[30][N], M[N], R = 0, n, tim;
char C[N]; string S[N]; vector<int> adj[N]; multiset<int, greater<int>> st[N];

void add(string X) {
    int v = 0;
    for (char c : X) {
        int t = (c - 'a');
        if (!trie[t][v]) trie[t][v] = ++tim;
        v = trie[t][v];
    }
    M[v] = 1;
}

void DFS(int v) {
    for (int u : adj[v]) {
        DFS(u);
        for (int x : st[u]) st[v].insert(x + 1);
        st[u] = {};
    }
    if (M[v]) st[v].insert(0);
    else st[v].erase(st[v].begin()), st[v].insert(0);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%s", C);
        S[i] = C;
    }
    for (int i = 1; i <= n; i++) {
        add(S[i]);
    }
    for (int i = 0; i <= tim; i++) {
        for (int j = 0; j < 26; j++) {
            if (trie[j][i]) adj[i].push_back(trie[j][i]);
        }
    }
    M[0] = 1;
    DFS(0);
    for (int h : st[0]) R += h;
    printf("%d\n", R);
    return 0;
}
