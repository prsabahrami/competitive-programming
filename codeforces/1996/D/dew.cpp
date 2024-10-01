#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long int ll;
typedef pair<int, int> pii;
 
#define F first
#define S second
#define lc id << 1
#define rc lc | 1
 
constexpr int N = 1e6 + 10, MOD = 1e9 + 7;

int main() {
    int q;
    scanf("%d", &q);
    for (; q--; ) {
        int n, x; scanf("%d%d", &n, &x);
        for (int i = 1; i <= x - 2; i++) { // a
            int y = x - i; // max b + c; 
            // max bc = n - i * y; 
            int maxmul = y * y / 4;
            // if b + c = t, we need b * (t - b) <= n - i * t -> 
        }
    }
    return 0;
}
