#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int sum;
    Node* left;
    Node* right;
    Node() : sum(0), left(nullptr), right(nullptr) {}
};
class SegmentTree {
public:
    SegmentTree(int N, const vector<int>& a)
        : n_Nodes(0), n_Size(N), nodes(vector<Node>(N * 2)), val(a) {
        this->build(0, n_Size);
        val.clear();
    }
    Node* build(int l, int r) {
        Node* u = &nodes[n_Nodes++];
        if (r - l == 1) {
            u->sum = val[l];
        } else {
            int m = (l + r) / 2;
            u->left = build(l, m);
            u->right = build(m, r);
            u->sum = u->left->sum + u->right->sum;
        }
        return u;
    }
    // val[i] += d
    void update(int i, int d) { _update(&nodes[0], 0, n_Size, i - 1, d); }
    void _update(Node* u, int l, int r, int i, int d) {
        if (i < l || i >= r)
            return;
        u->sum += d;
        if (r - l == 1)
            return;
        int m = (l + r) / 2;
        _update(u->left, l, m, i, d);
        _update(u->right, m, r, i, d);
    }
    int query(int ql, int qr) {
        return _query(&nodes[0], 0, n_Size, ql - 1, qr);
    }
    int _query(Node* u, int l, int r, int ql, int qr) {
        if (r <= ql || l >= qr)
            return 0;
        if (ql <= l && r <= qr)
            return u->sum;
        int m = (l + r) / 2;
        // cout << m << endl;
        return _query(u->left, l, m, ql, qr) + _query(u->right, m, r, ql, qr);
    }
    void print() {
        for (auto n : nodes) {
            cout << n.sum << " ";
        }
        cout << endl;
    }

private:
    int n_Nodes, n_Size;
    vector<Node> nodes;
    vector<int> val;
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    SegmentTree tree(n, a);
    tree.print();
    string c;
    int i, j;
    while (1) {
        cin >> c;
        if (c[0] == 'E')
            break;
        cin >> i >> j;
        if (c[0] == 'Q') {
            cout << tree.query(i, j) << '\n';
        } else {
            if (c[0] == 'S')
                j = -j;
            tree.update(i, j);
        }
    }
}
