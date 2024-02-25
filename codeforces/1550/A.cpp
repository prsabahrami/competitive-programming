/* I do it for the glory */
#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
 
#define SZ(x)                       (int) x.size()
#define F                           first
#define S                           second

const int N = 1e6 + 10, MOD = 1e9 + 7;

int main() {
    int t, s; scanf("%d", &t);
    for (; t; t--) {
        scanf("%d", &s);
         int c = 0;
        for (int i = 1; i <= s; i += 2) 
            s -= i, c++;
        if (s) c++;
        printf("%d\n", c);
    }
    return 0;
}

