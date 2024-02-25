/// IN THE NAME OF GUITAR
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long int ll;
typedef pair<ll, ll> pll;
 
#define sz(x)                       (ll) x.size()
#define all(x)                      (x).begin(),(x).end()
#define F                           first
#define S                           second
#define lc 							id << 1
#define rc 							lc | 1

ll Pow(ll a, ll b, ll md, ll ans = 1) {
    for (; b; b >>= 1, a = a * a % md)
        if (b & 1)
            ans = ans * a % md;
    return ans % md;
}
const ll MAXN = 1e5 + 10;
const ll INF  = 8e18;
const ll MOD  = 1e9 + 7;
ll seg[MAXN << 2], lazy[MAXN << 2], cnt[MAXN << 2], L[MAXN], R[MAXN], V[MAXN], U[MAXN], ans[MAXN], timer = 0, n, q;
vector<ll> adj[MAXN], vec[MAXN];

void merge(ll id) {
	seg[id] = min(seg[lc], seg[rc]);
	cnt[id] = 0;
	if (seg[id] == seg[rc]) cnt[id] += cnt[rc];
	if (seg[id] == seg[lc]) cnt[id] += cnt[lc];
}

void build(ll id = 1, ll l = 0, ll r = MAXN) {
	if (r - l == 1) {
		cnt[id] = 1;
		return;
	}
	ll mid = (l + r) >> 1;
	build(lc, l, mid);
	build(rc, mid, r);
	merge(id);
}

void shift(ll id, ll l, ll r) {
	seg[id] += lazy[id];
	if (r - l > 1) {
		lazy[lc] += lazy[id];
		lazy[rc] += lazy[id];
	}
	lazy[id] = 0;
}

void update(ll ql, ll qr, ll val, ll id = 1, ll l = 0, ll r = MAXN) {
	shift(id, l, r);
	if (qr <= l || r <= ql || ql >= qr) return;
	if (ql <= l && r <= qr) {
		lazy[id] += val;
		shift(id, l, r);
		return;
	}
	ll mid = (l + r) >> 1;
	update(ql, qr, val, lc, l, mid);
	update(ql, qr, val, rc, mid, r);
	merge(id);
}

pll get(ll ql, ll qr, ll id = 1, ll l = 0, ll r = MAXN) {
	shift(id, l, r);
	if (qr <= l || r <= ql) return {INF, 0};
	if (ql <= l && r <= qr) return {seg[id], cnt[id]};
	ll mid = (l + r) >> 1;
	pll x = get(ql, qr, lc, l, mid), res;
	pll y = get(ql, qr, rc, mid, r);
	res.F = min(x.F, y.F);
	if (res.F == y.F) res.S += y.S;
	if (res.F == x.F) res.S += x.S;
	return res;
}

void preDFS(ll v, ll p = -1) {
	L[v] = timer++;
	for (ll u : adj[v]) {
		if (u != p) preDFS(u, v);
	}
	R[v] = timer;
}

void DFS(ll v, ll p = -1) {
	for (ll i : vec[v]) {
		update(L[V[i]], R[V[i]], 1);
		update(L[U[i]], R[U[i]], 1);
	}
	pll X = get(L[1], R[1]), Y = get(L[v], L[v] + 1);
	//if (v == 2) printf("TEST %lld\n", Y.F);
	if (Y.F == 0) ans[v] = 0;
	else if (X.F == 0) ans[v] = n - 1 - X.S;
	else ans[v] = n - 1;
	for (ll u : adj[v]) {
		if (u != p) DFS(u, v);
	}
	for (ll i : vec[v]) {
		update(L[V[i]], R[V[i]], -1);
		update(L[U[i]], R[U[i]], -1);
	}
}

int main() {
	scanf("%lld%lld", &n, &q);
	for (ll i = 1; i <= n - 1; i++) {
		ll u, v; scanf("%lld%lld", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	build();
	for (ll i = 1; i <= q; i++) {
		scanf("%lld%lld", &V[i], &U[i]);
		vec[U[i]].push_back(i);
		vec[V[i]].push_back(i);
	}
	preDFS(1);
	DFS(1);
	for (ll i = 1; i <= n; i++) printf("%lld ", ans[i]);
    return 0;
}

