#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;
 
#define SZ(x)                       (ll) x.size()
#define F                           first
#define S                           second

const ll N = 1e6 + 10;
int t; char S[N];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%s", S + 1);
		stack<int> st1, st2; int ans = 0, n = strlen(S + 1);
		for (int i = 1; i <= n; i++) {
			if (S[i] == '(') st1.push(i);
			if (S[i] == '[') st2.push(i);
			if (S[i] == ')' && SZ(st1)) ans++, st1.pop();
			if (S[i] == ']' && SZ(st2)) ans++, st2.pop();
		}
		printf("%d\n", ans);
	}
    return 0;
}

