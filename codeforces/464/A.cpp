#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
 
#define SZ(x)                       (int) x.size()
#define F                           first
#define S                           second

const int N = 1e3 + 10;
char S[N]; int n, p;
string C;

int check(int pos, char c) {
    if (pos > 1) return (c != C[pos - 1] && c != C[pos - 2]);
    else if (pos == 1) return c != C[pos - 1];
    else return 1;
}

int main() {
    scanf("%d%d%s", &n, &p, S);
    C = S; 
    for (int i = n - 1; ~i; i--) {
        C = S; int ptr = -1;
        for (int j = C[i] - 'a' + 2; j <= p; j++) {
            if (check(i, j + 'a' - 1)) {
                ptr = j;
                break;
            }
        }
        if (ptr == -1) continue;
        C[i] = (ptr + 'a' - 1);
        int gf = 1, f = 0;
        for (int j = i + 1; gf && j < n; j++) {
            f = 0;
            for (int k = 1; k <= p; k++) {
                if (check(j, k + 'a' - 1)) {
                    C[j] = k + 'a' - 1;
                    f = 1;
                    break;
                }
            }
            if (!f) gf = 0;
        }
        if (!gf) continue;
        for (char c : C) printf("%c", c);
        return 0;
    }
    printf("NO\n");
    return 0;
}
