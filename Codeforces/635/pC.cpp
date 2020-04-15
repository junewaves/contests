// Codeforces Round #635 (Div. 2) (4/15)
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int ll;
struct Node {
    int parent, depth, c;
};
int n, k, a, b;
vector<vector<int>> edges;
vector<Node> tree;
int setNode(int p, int ni, int d) {
    tree[ni].c = 1;
    tree[ni].depth = d;
    tree[ni].parent = p;
    for (auto pp : edges[ni]) {
        if (pp != p) {
            tree[ni].c += setNode(ni, pp, d + 1);
        }
    }
    return tree[ni].c;
}
void solve() {
    cin >> n >> k;
    // edges.resize(n, vector<bool>(n, false));
    edges.resize(n);
    tree.resize(n);
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        edges[b - 1].push_back(a - 1);
        edges[a - 1].push_back(b - 1);
    }
    setNode(-1, 0, 0);
    vector<int> id(n);
    for (int i = 0; i < n; i++)
        id[i] = i;
    sort(id.begin(), id.end(), [&](int x, int y) {
        if (tree[x].depth - tree[x].c != tree[y].depth - tree[y].c)
            return tree[x].depth - tree[x].c > tree[y].depth - tree[y].c;
        else if (tree[x].depth != tree[y].depth)
            return tree[x].depth > tree[y].depth;
        else
            return tree[x].c < tree[y].c;
    });
    int sum = 0;
    for (int i = 0; i < k; i++) {
        sum += tree[id[i]].depth - tree[id[i]].c + 1;
    }
    cout << sum << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}