/* I do it for the glory */
#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
 
#define SZ(x)                       (int) x.size()
#define F                           first
#define S                           second

const int N = 1e5 + 10, MOD = 1e9 + 7, SQ = 320;
int M[N], C[N], R[N], A[N], n, q, l[N], r[N], ord[N]; ll ans[N];
vector<int> vec;

void add(int id) {
    if (!id) return;
    int x = A[id];
    if (C[x]) M[C[x]]--;
    C[x]++; 
    M[C[x]]++; vec.push_back(C[x]);
}

void rmv(int id) {
    if (!id) return;
    int x = A[id];
    M[C[x]]--;
    C[x]--;
    if (C[x]) M[C[x]]++, vec.push_back(C[x]);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) 
        scanf("%d", &A[i]);
    scanf("%d", &q);
    for (int i = 1; i <= q; i++) {
        scanf("%d%d", &l[i], &r[i]);
    }
    iota(ord + 1, ord + q + 1, 1);
    sort(ord + 1, ord + q + 1, [&] (int i, int j) {
        return l[i] / SQ == l[j] / SQ ? r[i] < r[j] : l[i] < l[j];
    });
    int ml = 0, mr = 0; 
    for (int _ = 1; _ <= q; _++) {
        int k = ord[_];
        while (ml < l[k]) rmv(ml++);
        while (mr > r[k]) rmv(mr--);
        while (ml > l[k]) add(--ml);
        while (mr < r[k]) add(++mr);
        vector<int> cev;
        for (int &x : vec) if (M[x]) cev.push_back(x);
        sort(begin(cev), end(cev));
        cev.resize(unique(begin(cev), end(cev)) - begin(cev));
        vec.swap(cev); priority_queue<int> pq; ll ret = 0;
        for (int &x : vec) {
            if (x >= SQ) for (int j = 0; j < M[x]; j++) 
                pq.push(-x);
        }
        for (int i = 1; i < SQ; i++) {
            R[i] = M[i];
        }
        int rem = 0;
        for (int i = 1; i < SQ; i++) {
            if (R[i]) {
                if (rem)  { R[i]--, ret += i + rem; R[i + rem]++, rem = 0; }
                ret += (R[i] - (R[i] & 1)) * i;
                R[2 * i] += R[i] >> 1;
                if (R[i] & 1) rem = i;
                R[i] = 0;
            }
        }
        if (rem) pq.push(-rem);
        for (int i = SQ; i <= 2 * SQ; i++) {
            for (int j = 0; j < R[i]; j++) pq.push(-i);
            R[i] = 0;
        }
        while (SZ(pq) > 1) {
            int x = pq.top(); pq.pop();
            int y = pq.top(); pq.pop();
            ret += -x - y;
            pq.push(x + y);
        }
        ans[k] = ret;
    }
    for (int i = 1; i <= q; i++) 
        printf("%lld\n", ans[i]);
    return 0;
}

