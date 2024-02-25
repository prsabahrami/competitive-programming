#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
 
#define SZ(x)                       (int) x.size()
#define F                           first
#define S                           second

const int N = 1e6 + 10, MOD = 1e9 + 7;
int q;

int main() {
	scanf("%d", &q);
	while (q--) {
		int n;
		string t; cin >> n >> t;
		sort(t.begin(), t.end());
		cout << t << endl;
	}
	return 0;
}
