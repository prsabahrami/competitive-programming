/* I do it for the glory */
#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
 
#define SZ(x) (int) x.size()
#define F first
#define S second

const int N = 1e6 + 10, MOD = 1e9 + 7;

int main() {
    int t;
    for (scanf("%d", &t); t; t--) {
        int n; scanf("%d", &n); string s; cin >> s;
        string t = s; int c = 0;
        sort(s.begin(), s.end());
        for (int i = 0; i < n; i++) 
            if (s[i] != t[i]) c++;
        printf("%d\n", c);
    }
    return 0;
}

