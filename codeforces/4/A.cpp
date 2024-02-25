#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;

#define F first
#define S second

constexpr int N = 1e5 + 10, MOD = 1e9 + 7;

int main() {
    int n; cin >> n;
    cout << (n % 2 == 1 || n == 2 ? "NO\n" : "YES\n");
    return 0;
}