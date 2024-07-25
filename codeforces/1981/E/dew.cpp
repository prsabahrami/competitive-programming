// Damn, I'm getting old
#include <bits/stdc++.h>
#pragma GCC optimize("O2")
 
using namespace std;
 
typedef long long int ll;
typedef pair<int, int> pii;
 
#define F first
#define S second
#define lc id << 1
#define rc lc | 1
 
constexpr int N = 5e5 + 10, MOD = 1e9 + 7;
int L[N], R[N], A[N], P[N], sz[N], C[N], val[N], n;
vector<int> comp, vecL[2 * N], vecR[2 * N];
multiset<pii> st;

int getpar(int v) {
    if (P[v] == -1) return v;
    return P[v] = getpar(P[v]);
}

int merge(int u, int v) {
    u = getpar(u), v = getpar(v);
    if (u == v) return 0;
    if (sz[u] < sz[v]) swap(u, v);
    P[v] = u, sz[u] += sz[v];
    return 1;
}

ll solve() {
    st.clear();
    for (int i = 1; i <= n; i++) C[i] = -1, val[i] = 0;
    vector<pair<int, pii>> E;
    for (int i = 1; i <= 2 * n; i++) {
        for (auto p : vecL[i]) {
            st.insert({A[p], getpar(p)});
            int x = A[p];
            int tp = getpar(p);
            auto nxt = st.find({A[p], tp});
            if (++nxt != st.end()) {
                if (nxt->S != tp) {
                    C[nxt->S] = tp;
                    E.push_back({abs(nxt->F - x), {nxt->S, tp}});
                }
                if (nxt->S != tp) {
                    C[tp] = nxt->S;
                    E.push_back({abs(nxt->F - x), {tp, nxt->S}});
                }
            }
            --nxt;
            if (nxt != st.begin()) {
                nxt--;
                if (nxt->S != tp) {
                    C[nxt->S] = tp;
                    val[nxt->S] = abs(nxt->F - x);
                    E.push_back({abs(nxt->F - x), {nxt->S, tp}});
                }
                if (nxt->S != tp) {
                    C[tp] = nxt->S;
                    val[tp] = abs(nxt->F - x);
                    E.push_back({abs(nxt->F - x), {tp, nxt->S}});
                }
            }
        }
        for (auto p : vecR[i]) {
            st.erase(st.find({A[p], getpar(p)}));
        }
    }
    ll tot = 0;
    for (int i = 1; i <= n; i++) {
        if (C[i] == -1) return -1;
    }
    sort(E.begin(), E.end());
    for (auto p : E) {
        if (merge(p.S.F, p.S.S)) {
            tot += p.F;
        }
    }
    return tot;
}

int Main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d%d%d", L + i, R + i, A + i);
    for (int i = 1; i <= n; i++) P[i] = -1, sz[i] = 1;
    for (int i = 1; i <= n; i++) comp.push_back(L[i]), comp.push_back(R[i]);
    sort(comp.begin(), comp.end());
    comp.resize(unique(comp.begin(), comp.end()) - comp.begin());
    for (int i = 1; i <= n; i++) L[i] = lower_bound(comp.begin(), comp.end(), L[i]) - comp.begin() + 1;
    for (int i = 1; i <= n; i++) R[i] = lower_bound(comp.begin(), comp.end(), R[i]) - comp.begin() + 1;
    ll res = 0;
    for (int i = 1; i <= n; i++) {
        vecL[L[i]].push_back(i);
        vecR[R[i]].push_back(i);
    }
    for (int i = 1; i <= 19; i++) {
        if (sz[getpar(1)] == n) {
            printf("%lld\n", res);
            return 0;
        }
        ll x = solve();
        if (x == -1) break;
        res += x;
    }
    printf("-1\n");
    return 0;
}

int main() {
    int q;
    scanf("%d", &q);
    for (int i = 1; i <= q; i++) {
        Main();
        comp.clear();
        for (int j = 1; j <= 2 * n; j++) vecL[j].clear(), vecR[j].clear();
    }
    return 0;
}
