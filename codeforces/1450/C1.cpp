#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
 
#define SZ(x)                       (int) x.size()
#define F                           first
#define S                           second

const int N = 310 + 10, MOD = 1e9 + 7;
char A[N][N]; int n, q, C[2][3];

int main() {
	scanf("%d", &q);
	while (q--) {
		scanf("%d", &n);
		for (int i = 0; i < 2; i++) for (int j = 0; j < 3; j++) C[i][j] = 0;
		for (int i = 0; i < n; i++) scanf("%s", A[i]);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (A[i][j] == 'X') C[0][(i + j) % 3]++;
				if (A[i][j] == 'O') C[1][(i + j) % 3]++;
			}
		}
		int mn = MOD, x, y;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (i == j) continue;
				if (C[1][i] + C[0][j] < mn) {
					mn = C[1][i] + C[0][j], x = i, y = j;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int xx = (i + j) % 3;
				if (xx == x && A[i][j] == 'O') A[i][j] = 'X';
				if (y == xx && A[i][j] == 'X') A[i][j] = 'O';
				cout << A[i][j];
			}
			cout << endl;
		}
	}
	return 0;
}
