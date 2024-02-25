/* There's someone in my head but it's not me */ 
#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
 
#define SZ(x)                       (int) x.size()
#define F                           first
#define S                           second
#define lc                          id << 1
#define rc                          lc | 1

const int N = 5e5 + 10, MOD = 1e9 + 7;
int ord[N], pos[N], rnk[19][N], L[19][N], R[19][N], dp[N], seg[N << 2], n; char S[N];

void modify(int p, int x, int id = 1, int l = 1, int r = n + 1) {
    if (r - l < 2) {
        seg[id] = x;
        return;
    }
    int md = (l + r) >> 1;
    if (p < md) modify(p, x, lc, l, md);
    else modify(p, x, rc, md, r);
    seg[id] = max(seg[lc], seg[rc]);
}

int get(int ql, int qr, int id = 1, int l = 1, int r = n + 1) {
    if (qr <= l || r <= ql) return 0;
    if (ql <= l && r <= qr) return seg[id];
    int md = (l + r) >> 1;
    return max(get(ql, qr, lc, l, md), get(ql, qr, rc, md, r));
}

void buildSA() {
    for (int i = 1; i <= n; i++) rnk[0][i] = S[i] - 'a', ord[i] = i;
    for (int pw = 0; pw < 18; pw++) {
        auto cmp = [&] (const int &x, const int &y) {
            if (rnk[pw][x] != rnk[pw][y]) return rnk[pw][x] < rnk[pw][y];
	        if (max(x, y) + (1 << pw) > n + 1) return x > y;
	        return rnk[pw][x + (1 << pw)] < rnk[pw][y + (1 << pw)];
        };
        sort(ord + 1, ord + n + 1, cmp);
        for (int i = 2; i <= n; i++) 
            rnk[pw + 1][ord[i]] = rnk[pw + 1][ord[i - 1]] + cmp(ord[i - 1], ord[i]);
    }
}

int LCP(int x, int y) {
    if (x > y) swap(x, y);
    int ret = 0;
    for (int i = 19; i--;) if (y + (1 << i) <= n + 1 && rnk[i][x] == rnk[i][y]) {
		ret ^= (1 << i);
		x += (1 << i); y += (1 << i);
	}
    return ret;
}

int check(int p, int x) {
    int l = p, r = p;
    for (int i = 19; i--;) {
        if (r + (1 << i) <= n + 1 && L[i][r] >= x) r += 1 << i;
        if (l - (1 << i) > -1 && R[i][l] >= x) l -= 1 << i;
    }
    return get(l, r + 1) >= x;
}

int main() {
    scanf("%d%s", &n, S + 1);
    buildSA(); 
    for (int i = 1; i <= n; i++) 
        pos[ord[i]] = i;
    for (int i = 1; i <= n; i++) {
        if (i < n) L[0][i] = LCP(ord[i], ord[i + 1]); 
        if (i > 1) R[0][i] = LCP(ord[i], ord[i - 1]);
    }
    for (int j = 0; j + 1 < 19; j++) {
        for (int i = 1; i <= n; i++) if (i + (1 << (j + 1)) <= n + 1) {
            L[j + 1][i] = min(L[j][i], L[j][i + (1 << j)]);
        }
        for (int i = 1; i <= n; i++) if (i - (1 << (j + 1)) > -1) {
            R[j + 1][i] = min(R[j][i], R[j][i - (1 << j)]);
        }
    }
    dp[n] = 1; int ptr = n;
    for (int i = n - 1; i; i--) {
        for (dp[i] = dp[i + 1] + 1;; dp[i]--) {
            for (; i + dp[i] <= ptr; ptr--) modify(pos[ptr], dp[ptr]);
            if (check(pos[i], dp[i] - 1) || check(pos[i + 1], dp[i] - 1)) break;
        }
    }
    printf("%d\n", *max_element(dp, dp + N));
    return 0;
}
