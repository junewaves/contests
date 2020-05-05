#include <bits/stdc++.h>
using namespace std;
struct Node {
    int mx;
    Node *left, *right;
    Node() : mx(0), left(nullptr), right(nullptr){};
};
constexpr const int MAXN = 1e5;
Node nodes[MAXN << 1];
int used = 0, val[MAXN];

Node* build(int l, int r) {
    Node* u = &nodes[used++];
    if (r - l == 1) {
        u->mx = val[l];
    } else {
        int m = (l + r) / 2;
        u->left = build(l, m);
        u->right = build(m, r);
        u->mx = max(u->left->mx, u->right->mx);
    }
    return u;
}
int update(Node* u, int l, int r, int i, int v) {
    if (i < l || i >= r)
        return u->mx;
    if (r - l == 1)
        return u->mx = v;
    int m = (l + r) / 2;
    u->mx = max(update(u->left, l, m, i, v), update(u->right, m, r, i, v));
    return u->mx;
}
int query(Node* u, int l, int r, int ql, int qr) {
    if (r <= ql || l >= qr)
        return 0;
    if (ql <= l && r <= qr)
        return u->mx;
    int m = (l + r) / 2;
    return max(query(u->left, l, m, ql, qr), query(u->right, m, r, ql, qr));
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> val[i];
    }
    Node* root = build(0, n);  // build segment tree
    while (m--) {
        int act, a, b;
        cin >> act >> a >> b;
        if (act == 1) {  // update
            update(root, 0, n, a - 1, b);
        } else {
            cout << query(root, 0, n, a - 1, b) << '\n';
        }
    }
}
