#include <bits/stdc++.h>
using namespace std;

struct Data {
    int a, b, c;

    Data(int _a = 0, int _b = 0, int _c = 0) {
        a = _a;
        b = _b;
        c = _c;
    }

    bool operator < (const Data& o) const {
        return b != o.b ? b < o.b : a != o.a ? a < o.a : c < o.c;
    }
};

const int MX = 50050;

int n;
Data p[MX];

void init(void) {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int a, b, c; cin >> a >> b >> c;
        ++a, ++b;
        p[i] = Data(a, b, c);
    }
    sort(p + 1, p + n + 1);
}

struct node {
    int val;
    bool lz;

    node(int _val = 0, bool _lz = false) {
        val = _val; lz = _lz;
    }
};

node comb(const node& x, const node& y) {
    node res;
    res.val = x.val + y.val;
    return res;
}

struct segtree {
    int n;
    vector<node> st;

    segtree(int _n = 0) {
        n = _n;
        st.assign(4 * n + 5, node());
    }

    void pushDown(int id, int l, int r) {
        if (!st[id].lz) return;
        int mid = (l + r) >> 1;
        int x = id << 1, y = x | 1;
        st[x].val = mid - l + 1;
        st[x].lz = true;
        st[y].val = r - mid;
        st[y].lz = true;
        st[id].lz = false;
    }

    void update(int id, int l, int r, int u, int v) {
        if (r < u || l > v) return;
        if (u <= l && r <= v) {
            st[id].val = r - l + 1;
            st[id].lz = true;
            return;
        }
        pushDown(id, l, r);
        int mid = (l + r) >> 1;
        int x = id << 1, y = x | 1;
        update(x, l, mid, u, v); update(y, mid + 1, r, u, v);
        st[id] = comb(st[x], st[y]);
    }

    void update(int u, int v) {
        update(1, 1, n, u, v);
    }

    node get(int id, int l, int r, int u, int v) {
        if (r < u || l > v) return node();
        if (u <= l && r <= v) return st[id];
        pushDown(id, l, r);
        int mid = (l + r) >> 1;
        int x = id << 1, y = x | 1;
        return comb(get(x, l, mid, u, v), get(y, mid + 1, r, u, v));
    }

    int get(int u, int v) {
        return get(1, 1, n, u, v).val;
    }
};

void solve(void) {
    int ans = 0;
    segtree seg(MX);

    for (int i = 1; i <= n; ++i) {
        int a = p[i].a, b = p[i].b, c = p[i].c;
        int x = seg.get(a, b);
        if (x >= c) continue;
        int d = c - x;
        int l = 1, r = b;
        int pos = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            x = seg.get(mid, b);
            int val = b - mid + 1 - x;
            if (val == d) {
                pos = mid;
                break;
            }
            if (val < d) r = mid - 1;
            else l = mid + 1;
        }
        seg.update(pos, b);
        ans += d;
    }

    cout << ans << '\n';
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int tc; cin >> tc;
    while (tc--) {
        init();
        solve();
    }
    return 0;
}
