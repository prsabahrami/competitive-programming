#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long int ll;
typedef pair<int, int> pii;
 
#define F first
#define S second
#define lc id << 1
#define rc lc | 1
 
constexpr int N = 1e5 + 10, MOD = 1e9 + 7;

int main() {
    int q;
    for (scanf("%d", &q); q--; ) {
        int n;
        scanf("%d", &n);
        printf("%d\n", n / 4 + (n % 4) / 2);
    }
    return 0;
}
