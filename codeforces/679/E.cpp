/// Dispute --- Yann Tiersen
#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;
 
#define SZ(x)                       (ll) x.size()
#define F                           first
#define S                           second
#define lc 							id << 1
#define rc 							lc | 1

const ll N = 1e5 + 10, INF = 1e18;
vector<ll> jazz; set<ll> rock;
ll peek[N << 2], guitar[N << 2], piano[N], n, q;

ll violin(ll x) {
	return *lower_bound(jazz.begin(), jazz.end(), x);
}

void amplifier(int id, int l, int r) {
	guitar[id] += peek[id];
	if (r - l > 1) {
		peek[lc] += peek[id];
		peek[rc] += peek[id];
	}
	peek[id] = 0;
}

void practice(int pos, ll x, int id = 1, int l = 0, int r = N) {
	amplifier(id, l, r);
	if (r - l == 1) {
		guitar[id] = x;
		return;
	}
	int mid = (l + r) >> 1;
	amplifier(lc, l, mid), amplifier(rc, mid, r);
	if (pos < mid) practice(pos, x, lc, l, mid);
	else practice(pos, x, rc, mid, r);
	guitar[id] = min(guitar[lc], guitar[rc]);
}

void newguitar(int ql, int qr, ll x, int id = 1, int l = 0, int r = N) {
	amplifier(id, l, r);
	if (qr <= l || r <= ql) return;
	if (ql <= l && r <= qr) {
		peek[id] += x;
		return amplifier(id, l, r);
	}
	int mid = (l + r) >> 1;
	newguitar(ql, qr, x, lc, l, mid);
	newguitar(ql, qr, x, rc, mid, r);
	guitar[id] = min(guitar[lc], guitar[rc]);
}

ll stage(int ql, int qr, int id = 1, int l = 0, int r = N) {
	amplifier(id, l, r);
	if (qr <= l || r <= ql) return INF;
	if (ql <= l && r <= qr) return guitar[id];
	int mid = (l + r) >> 1;
	return min(stage(ql, qr, lc, l, mid), stage(ql, qr, rc, mid, r));
}

int tune(int ql, int qr, int id = 1, int l = 0, int r = N) {
	amplifier(id, l, r);
	if (qr <= l || r <= ql || guitar[id] > 0) return 0;
	if (r - l == 1) {
		int  f = 0;
		piano[l] = piano[l] - guitar[id];
		if (violin(piano[l]) == piano[l]) f = 1;
		ll x = violin(piano[l] + 1);
		guitar[id] = x - piano[l];
		piano[l] = x;
		return f;
	}
	int mid = (l + r) >> 1;
	int a = tune(ql, qr, lc, l, mid);
	int b = tune(ql, qr, rc, mid, r);
	guitar[id] = min(guitar[lc], guitar[rc]);
	return a || b;
}

ll drums(int x) {
	int y = *rock.lower_bound(x);
	return piano[y] - stage(y, y + 1);
}

int main() {
	for (ll pw = 1; pw < INF / 42; pw *= 42) jazz.push_back(pw);
	scanf("%lld%lld", &n, &q);
	for (int i = 1; i <= n; i++) {
		rock.insert(i);
		ll x; scanf("%lld", &x);
		practice(i, violin(x) - x);
		piano[i] = violin(x);
	}
	while (q--) {
		int t, l, r; ll x;
		scanf("%d", &t);
		if (t == 1) {
			scanf("%d", &l);
			printf("%lld\n", drums(l));
		} else if (t == 2) {
			scanf("%d%d%lld", &l, &r, &x);
			if (l > 1) {
                ll y = drums(l - 1); piano[l - 1] = violin(y);
				practice(l - 1, piano[l - 1] - y); rock.insert(l - 1);
			} 
			auto it = rock.lower_bound(l);
			while (it != rock.end()) {
				if (*it >= r) break;
				practice(*it, INF);
				it = rock.erase(it);
			}
			piano[r] = violin(x);
			rock.insert(r);
			practice(r, piano[r] - x);
		} else {
			scanf("%d%d%lld", &l, &r, &x);
			if (l > 1) {
                ll y = drums(l - 1); piano[l - 1] = violin(y);
				practice(l - 1, piano[l - 1] - y); rock.insert(l - 1);
			}
            ll y = drums(r);
            piano[r] = violin(y);
            practice(r, piano[r] - y);
            rock.insert(r);
			newguitar(l, r + 1, -x);
			while (1) {
				y = stage(l, r + 1);
				if (y > 0) break;
				if (tune(l, r + 1))
					newguitar(l, r + 1, -x);
			}
		}
	}
    return 0;
}

