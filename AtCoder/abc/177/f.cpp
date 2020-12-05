#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

constexpr int INF = 1e9 + 5;

struct segTree {
    int B = 1;
    vector<int> tag;
    vector<int> t;
    segTree(int n) {
        while (B < n) B *= 2;
        tag.resize(B, 0);
        t.resize(2 * B);
    }
    void pull(int u) {
        t[u] = min(t[u << 1], t[u << 1 | 1]);
    }
    void push(int u, int L, int R) {
        if (tag[u] == 0) return;
        int M = (L + R) / 2, lc = u << 1, rc = u << 1 | 1;
        t[lc] =  tag[u];
        t[rc] = tag[u] + (M - L);
        if (rc < B) {
            tag[lc] = tag[u];
            tag[rc] = tag[u] + (M - L);
        }
        tag[u] = 0;
    }
    void update(int u, int L, int R, int ql, int qr, int v) {
        if (R <= ql || qr <= L)
            return;
        if (ql <= L && R <= qr) {
            t[u] =  v;
            if (u < B) tag[u] = v;
            return;
        }
        push(u, L, R);
        int M = (L + R) / 2, lc = u << 1, rc = u << 1 | 1;
        update(lc, L, M, ql, qr, v);
        update(rc, M, R, ql, qr, v + max(0, (M - max(L, ql))));
        pull(u);
    }
    void update(int l, int r, int v) {
        update(1, 0, B, l, r, v);
    }
    int query(int u, int L, int R, int ql, int qr) {
        if (R <= ql || qr <= L)
            return INF;
        if (ql <= L && R <= qr)
            return t[u];
        push(u, L, R);
        int M = (L + R) / 2, lc = u << 1, rc = u << 1 | 1;
        int ret = min(query(lc, L, M, ql, qr), query(rc, M, R, ql, qr));
        return ret;
    }
    int query(int l, int r) {
        return query(1, 0, B, l, r);
    }
};


int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    bool dead = false;
    int l, r, ans = 0;
    segTree st(m);
    for (int z = 1; z <= n; z++) {
        cin >> l >> r;
        if (dead) {
            cout << "-1\n";
            continue;
        }
        l--, r--;
        int vl = l == 0 ? INF : st.query(l - 1, l);
        st.update(l, r + 1, vl + 1);
        ans = st.query(0, m);
        if (ans >= INF) {
            cout << "-1\n";
            dead = true;
        } else {
            cout << ans + z << '\n';
        }
    }
    return 0;
}