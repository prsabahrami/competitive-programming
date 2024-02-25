/* I do it for the glory */
#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
 
#define SZ(x) (int) x.size()
#define F first
#define S second

const int N = 1e5 + 4, MOD = 1e9 + 7;
int n, lst[30], L[N], R[N], psL[N][27], psR[N][27], dp[N][27], pd[N][27];
int ptL[N], ptR[N], dp2[17][N], dp3[17][N];
char S[N]; ll dps[17][N], pds[17][N], ret;

int main() {
    scanf("%s", S);
    n = strlen(S);
    for (int i = 0; i < n; i++){
		L[i] = lst[S[i] - 'a'];
		lst[S[i] - 'a'] = i;
		for (int j = 0; j < 26; j++)
			psL[i][j] = lst[j];
		sort(psL[i], psL[i] + 26);
		reverse(psL[i], psL[i] + 26);
		psL[i][26] = -1;
	}
    fill(lst, lst + 26, n - 1);
	for (int i = n - 1; ~i; i--){
		R[i] = lst[S[i] - 'a'];
		lst[S[i] - 'a'] = i;
		for (int j = 0; j < 26; ++ j)
			psR[i][j] = lst[j];
		sort(psR[i], psR[i] + 26);
		psR[i][26] = n;
	}
    for (int i = 0; i < n; i++) {
		ptL[i] = ptR[i] = dp[i][0] = pd[i][0] = i;
		for (int j = 0; j < 26; j++) {
			dp[i][j + 1] = min(dp[i][j], L[psR[i][j]]);
			pd[i][j + 1] = max(pd[i][j], R[psL[i][j]]);
		}
	}
    for (int _ = 1; _ <= 26; _++) {
		for (int i = 0; i < n; ++ i){
			dp2[0][i] = dp[i][_];
			dp3[0][i] = pd[i][_];
			dps[0][i] = pds[0][i] = i;
		}
		for (int i = 1; (1 << i) <= n; i++) {
			for (int j = 0; j < n; j++) {
				dp2[i][j] = dp2[i - 1][dp2[i - 1][j]];
				dp3[i][j] = dp3[i - 1][dp3[i - 1][j]];
				dps[i][j] = dps[i - 1][j] + dps[i - 1][dp2[i - 1][j]];
				pds[i][j] = pds[i - 1][j] + pds[i - 1][dp3[i - 1][j]];
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 31 - __builtin_clz(n); ~j; j--) {
				int nxL = dp2[j][ptL[i]], nxR = dp3[j][ptR[i]];
				if (nxR < psR[nxL][_]){
					ret += (ll(n - 1) << j) + dps[j][ptL[i]] - pds[j][ptR[i]];
					ptL[i] = nxL, ptR[i] = nxR;
				}
			}
			if (ptR[i] < psR[ptL[i]][_]){
				ret += n - 1 + ptL[i] - ptR[i];
				ptL[i] = dp[ptL[i]][_];
				ptR[i] = pd[ptR[i]][_];
			}
		}
	}
    printf("%lld\n", ret);
    return 0;
}

