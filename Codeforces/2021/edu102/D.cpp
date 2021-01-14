#include <bits/stdc++.h>
using namespace std;

struct Node {
    int vmin, vmax, vend;
    Node() : vmin(0), vmax(0), vend(0) {}
    Node(int n) : vmin(n), vmax(n), vend(n) {}
};

int n, m;
vector<Node> st;

Node combine(const Node& a, const Node& b) {
    Node res;
    res.vmin = min(a.vmin, b.vmin + a.vend);
    res.vmax = max(a.vmax, b.vmax + a.vend);
    res.vend = a.vend + b.vend;
    return res;
}

Node query(int l, int r) {
    Node L, R;
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
        if (l & 1) L = combine(L, st[l++]);
        if (r & 1) R = combine(st[--r], R);
    }
    return combine(L, R);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        cin >> n >> m;
        string ins;
        cin >> ins;
        st.resize(n * 2);
        for (int i = 0; i < n; i++)
            st[i + n] = Node(ins[i] == '+' ? 1 : -1);
        for (int i = n - 1; i > 0; i--)
            st[i] = combine(st[i << 1], st[i << 1 | 1]);
        while (m--) {
            int l, r;
            cin >> l >> r;
            auto res = combine(query(0, l-1), query(r, n));
            cout << res.vmax - res.vmin + 1 << '\n';
        }
    }
    return 0;
}

