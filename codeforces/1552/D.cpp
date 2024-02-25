/* I do it for the glory */
#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
 
#define SZ(x) (int) x.size()
#define F first
#define S second

const int N = 1e6 + 10, MOD = 1e9 + 7;
int t, n, A[N], B[N];

int main() {
    scanf("%d", &t); 
    for (; t; t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &A[i]);
        int f = 0;
        int pw = 1;
        for (int i = 1; i <= n; i++) pw *= 3;
        for (int i = 1; i < pw; i++) {
            vector<int> vec;
            int ti = i;
            for (int j = 0; j < n; j++) {
                if (i % 3 == 1) vec.push_back(1);
                else if (i % 3 == 2) vec.push_back(2);
                else vec.push_back(0);
                i /= 3;
            }
            i = ti;
            int sum = 0;
            for (int j = 0; j < n; j++) {
                if (vec[j] == 2) sum += -A[j];
                else if (vec[j]) sum += A[j];
            }
            if (sum == 0) f = 1;
        }
        if (f) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}

