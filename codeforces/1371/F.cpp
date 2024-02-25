#include <bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
 
#define SZ(x)                       (int) x.size()
#define F                           first
#define S                           second
#define lc                          id << 1
#define rc                          lc | 1

const int N = 5e5 + 10;
struct Nude {
    int a1, a2, sz, r1, l1, l2, r2;
    char l, r; 

    friend Nude operator+(Nude x, Nude y) {
        if (!x.sz) return y;
        if (!y.sz) return x;
        Nude z; z.sz = x.sz + y.sz;
        z.l1 = x.l1, z.r1 = y.r1, z.l2 = x.l2, z.r2 = y.r2;
        z.a1 = max(x.a1, y.a1), z.a2 = max(x.a2, y.a2); z.l = x.l, z.r = y.r;
        if (x.r != '<' || y.l != '>') {
            z.a1 = max(z.a1, x.r1 + y.l1);
            if (z.l1 == x.sz) z.l1 += y.l1;
            if (z.r1 == y.sz) z.r1 += x.r1;
        }
        if (x.r != '>' || y.l != '<') {
            z.a2 = max(z.a2, x.r2 + y.l2);
            if (z.l2 == x.sz) z.l2 += y.l2;
            if (z.r2 == y.sz) z.r2 += x.r2;
        }
        return z;
    } 
};
Nude seg[N << 2], EMP;
char S[N];
int n, q, lzy[N << 2];

void build(int id = 1, int l = 1, int r = n + 1) {
    if (r - l == 1) {
        seg[id].l = seg[id].r = S[l];
        seg[id].sz = 1;
        seg[id].l1 = seg[id].r1 = seg[id].a1 = seg[id].a2 = seg[id].l2 = seg[id].r2 = 1;
        //printf("id %d l %d r %d a1 %d a2 %d l1 %d r1 %d l2 %d r2 %d\n", id, l, r, seg[id].a1, seg[id].a2, seg[id].l1, seg[id].r1, seg[id].l2, seg[id].r2);
        return;
    }
    int mid = (l + r) >> 1;
    build(lc, l, mid);
    build(rc, mid, r);
    seg[id] = seg[lc] + seg[rc];
    //printf("id %d l %d r %d a1 %d a2 %d l1 %d r1 %d l2 %d r2 %d\n", id, l, r, seg[id].a1, seg[id].a2, seg[id].l1, seg[id].r1, seg[id].l2, seg[id].r2);
}

void shift(int id, int l, int r) {
    if (!lzy[id]) return;
    swap(seg[id].r1, seg[id].r2);
    swap(seg[id].l1, seg[id].l2);
    swap(seg[id].a1, seg[id].a2);
    seg[id].l ^= '>' ^ '<';
    seg[id].r ^= '>' ^ '<';
    if (r - l > 1) {
        lzy[lc] ^= 1;
        lzy[rc] ^= 1;
    }
    lzy[id] = 0;
}

void update(int ql, int qr, int id = 1, int l = 1, int r = n + 1) {
    shift(id, l, r);
    if (qr <= l || r <= ql) return;
    if (ql <= l && r <= qr) {
        lzy[id] ^= 1;
        return shift(id, l, r);
    }
    int mid = (l + r) >> 1;
    update(ql, qr, lc, l, mid);
    update(ql, qr, rc, mid, r);
    seg[id] = seg[lc] + seg[rc];
}

Nude get(int ql, int qr, int id = 1, int l = 1, int r = n + 1) {
    shift(id, l, r);
    if (qr <= l || r <= ql) return EMP;
    if (ql <= l && r <= qr) return seg[id];
    int mid = (l + r) >> 1;
    return get(ql, qr, lc, l, mid) + get(ql, qr, rc, mid, r);
}

int main() {
    EMP.sz = 0;
    scanf("%d%d%s", &n, &q, S + 1);
    build();
    //printf("%d\n", get(2, 5).a1);
    while (q--) {
        int l, r; scanf("%d%d", &l, &r);
        update(l, r + 1);
        printf("%d\n", get(l, r + 1).a1);
    }
    return 0;
}
