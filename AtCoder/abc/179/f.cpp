#include <bits/stdc++.h>
using namespace std;

struct LazySegTree {
    int B = 1;
    // check and change these for sure
    using S = int;
    vector<S> s;
    LazySegTree(int n) {
        while (B < n) B *= 2;
        // init tree
        s.resize(B * 2, INT_MAX);
    }
    void apply(int u, int x) {
        s[u] = min(s[u], x);
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
        update(lc, L, M, ql, qr, x...);
        update(rc, M, R, ql, qr, x...);
    }
    template<class... T>
    void update(int l, int r, T... x) {
        update(1, 0, B, l, r, x...);
    }
    S query(int u, int L, int R, int i) {
        if (R - L == 1)
            return s[u];
        int M = (L + R) / 2, lc = u << 1, rc = lc | 1;
        if (i < M)
            return min(s[u], query(lc, L, M, i));
        else
            return min(s[u], query(rc, M, R, i));
    }
    S query(int i) {
        return query(1, 0, B, i);
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    LazySegTree x(n), y(n);
    x.update(1, n - 1, n - 2);
    y.update(1, n - 1, n - 2);
    int64_t res = 0;
    while (q--) {
        int a, b;
        cin >> a >> b;
        if (a == 1) {
            int r = x.query(b - 1); 
            y.update(1, r + 1, b - 2);
            res += r;
        } else {
            int r = y.query(b - 1);
            x.update(1, r + 1, b - 2);
            res += r;
        }
    }
    int64_t N = n - 2;
    cout << N * N - res << '\n';
    return 0;
}