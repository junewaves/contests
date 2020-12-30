#include <bits/stdc++.h>
using namespace std;

struct LazySegTree {
    int B = 1;
    struct S {
        int mx = 0;
        int cnt = 1;
    };
    vector<S> s;
    vector<int> t;
    // check and change these for sure
    LazySegTree(int n) {
        while (B < n) B *= 2;
        // init tree
        s.resize(B * 2);
        t.resize(B);
        // build tree
        for (int u = B - 1; u > 0; u--) {
            s[u] = combine(s[u << 1], s[u << 1 | 1]);
        }
    }
    S combine(S l, S r) {
        S ret;
        ret.mx = max(l.mx, r.mx);
        ret.cnt = l.cnt * (l.mx == ret.mx) + r.cnt * (r.mx == ret.mx);
        return ret;
    }
    void apply(int u, int x) {
        s[u].mx += x;
        if (u < B) t[u] += x;
    }
    void push(int u) {
        if (t[u] == 0) return; // tag is not set
        apply(u << 1, t[u]);
        apply(u << 1 | 1, t[u]);
        t[u] = 0;
    }
    // *probably* dont need to change these
    template<class... T>
    void update(int u, int L, int R, int ql, int qr, T... x) {
        if (R <= ql || qr <= L) 
            return;
        if (ql <= L && R <= qr) {
            apply(u, x...);
            return;
        }
        int M = (L + R) / 2, lc = u << 1, rc = lc | 1;
        push(u); // for min/max operations
        // push(u, L ,R); // for sum operations
        update(lc, L, M, ql, qr, x...);
        update(rc, M, R, ql, qr, x...);
        // pull
        s[u] = combine(s[u << 1], s[u << 1 | 1]);
    }
    template<class... T>
    void update(int l, int r, T... x) {
        update(1, 0, B, l, r, x...);
    }
    S query(int u, int L, int R, int ql, int qr) {
        if (R <= ql || qr <= L) 
            return S{};
        if (ql <= L && R <= qr)
            return s[u];
        int M = (L + R) / 2, lc = u << 1, rc = lc | 1;
        push(u); // for min/max operations
        // push(u, L ,R); // for sum operations
        return combine(query(lc, L, M, ql, qr), query(rc, M, R, ql, qr));
    }
    S query(int l, int r) {
        return query(1, 0, B, l, r);
    }
};
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& it : a) cin >> it, --it;
    vector<vector<int>> pos(n);
    LazySegTree st(n);
    st.update(0, n, n);
    for (int i = 0; i < n; i++) {
        pos[i].push_back(n);
    }
    int64_t ans = 0;
    for (int l = n - 1; l >= 0; l--) {
        int v = a[l];
        auto update = [&](int value) {
            if ((int)pos[v].size() >= 4) {
                int third = *(pos[v].end() - 3);
                int fourth = *(pos[v].end() - 4);
                st.update(third, fourth, value);
            }
            st.update(0, pos[v].back(), value);
        };
        update(-1);
        pos[v].push_back(l);
        update(1);
        auto x = st.query(l, n);
        if (x.mx == n)
            ans += x.cnt;
    }
    cout << ans << '\n';
    return 0;
}