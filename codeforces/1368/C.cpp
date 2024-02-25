#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
 
#define SZ(x)                       (int) x.size()
#define F                           first
#define S                           second

const int N = 1e6 + 10, MOD = 1e9 + 7;
int n;

int main() {
	scanf("%d", &n);
	printf("%d\n", n * 3 + 4);
	printf("%d %d\n %d %d\n", 1, 1, 1, 2); int ptr = 1;
	for (int i = 2; i <= n + 1; i++) {
		printf("%d %d\n %d %d\n %d %d\n", i, ptr, i, ptr + 1, i, ptr + 2);
		ptr++;
	}
	printf("%d %d\n %d %d\n", n + 2, ptr, n + 2, ptr + 1);
	return 0;
}
