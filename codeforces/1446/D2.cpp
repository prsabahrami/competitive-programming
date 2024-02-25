/* I do it for the glory */
#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
 
#define SZ(x)                       (int) x.size()
#define F                           first
#define S                           second

const int N = 2e5 + 10, MOD = 1e9 + 7, SQ = 550;
int A[N], ps[N], lst[2 * N], C[N], n, mx, ret; 

void upd(int x) {
    memset(lst, -1, sizeof lst);
    lst[n] = 0;
    for (int i = 1, c = 0; i <= n; i++) {
        c += (A[i] == x);
        if (~lst[ps[i] - c + n]) 
            ret = max(ret, i - lst[ps[i] - c + n]);
        else lst[ps[i] - c + n] = i;
    }
}

void _upd(int x) {
    memset(C, 0, sizeof C); int pl = 1, pr = 1, f = 0;
    for (; pr <= n; pr++) {
        if (C[A[pr]] == x) f--;
        C[A[pr]]++;
        if (C[A[pr]] == x) f++;
        for (; C[A[pr]] > x; pl++) {
            if (C[A[pl]] == x) f--;
            C[A[pl]]--;
            if (C[A[pl]] == x) f++;
        }
        if (f > 1) ret = max(ret, pr - pl + 1);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &A[i]), C[A[i]]++;
    int ct = 0;
    for (int i = 1; i < N; i++) {
        if (C[i] < C[mx]) continue;
        if (C[i] > C[mx]) mx = i, ct = 1;
        else ct++;
    }
    if (ct > 1) return !printf("%d\n", n);
    for (int i = 1; i <= n; i++) 
        ps[i] = ps[i - 1] + (A[i] == mx);
    for (int i = 1; i < N; i++) {
        if (i != mx && C[i] >= SQ) upd(i);
    }
    for (int i = 1; i < SQ; i++) {
        _upd(i);
    }
    printf("%d\n", ret);
    return 0;
}

