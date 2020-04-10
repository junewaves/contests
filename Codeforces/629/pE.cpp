#include <bits/stdc++.h>
using namespace std;
#ifndef _VSCODE_DEBUG
#define endl '\n'
#endif
struct Node {
    int parent, depth;
    unordered_set<int> children;
};
int n, q, p, c;
// Node nodes[200005];
vector<Node> nodes;
void construct_tree() {
    for (int i = 1; i < n; i++) {
        cin >> p >> c;
        nodes[p].children.insert(c);
        nodes[c].children.insert(p);
    }
    nodes[1].parent = 0;
    nodes[1].depth = 0;
    for (auto v : nodes[1].children) {
        nodes[v].parent = 1;
        nodes[v].depth = 2;
    }
    for (int i = 2; i <= n; i++) {
        nodes[i].children.erase(nodes[i].parent);
        for (auto v : nodes[i].children) {
            nodes[v].parent = i;
            nodes[v].depth = nodes[i].depth + 1;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    nodes.resize(n + 1);
    construct_tree();
    // start queries
    for (int i = 0; i < q; i++) {
        cin >> p;
        vector<int> query(p);
        for (int j = 0; j < p; j++) {
            cin >> query[j];
        }
        sort(query.begin(), query.end(),
             [](int x, int y) { return nodes[x].depth > nodes[y].depth; });
        // for (int q : query) {
        //     cout << q << ", ";
        // }
        unordered_set<int> goodNodes = { 1 };
        int ptr = query[0];
        while (ptr > 1) {
            ptr = nodes[ptr].parent;
            goodNodes.insert(nodes[ptr].children.begin(),
                             nodes[ptr].children.end());
        }
        bool query_success = true;
        for (int j = 0; j < p; j++) {
            if (goodNodes.count(query[j]) == 0) {
                query_success = false;
                break;
            }
        }
        if (query_success)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}