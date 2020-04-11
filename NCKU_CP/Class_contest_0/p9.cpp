#include <bits/stdc++.h>
using namespace std;
// problem source: https://judge.csie.ncku.edu.tw/problems/9
// *segment tree problem
struct Node {
    int l, r;
    int max;
    Node *left, *right;
};
class segmentTree {
public:
    segmentTree(vector<int> input) : num(input), nodeCount(0) {
        tree = new Node[input.size() << 1];
        buildTree(&tree[0], 0, input.size() - 1);
    }
    ~segmentTree() { delete[] tree; }
    void buildTree(Node* root, int l, int r) {
        root->l = l;
        root->r = r;
        if (l == r) {
            root->max = num[l];
            return;
        }
        nodeCount++;
        root->left = &tree[nodeCount];
        nodeCount++;
        root->right = &tree[nodeCount];
        int m = (l + r) >> 1;  // find middle
        buildTree(root->left, l, m);
        buildTree(root->right, m + 1, r);
        root->max = max(root->left->max, root->right->max);
    }
    void update(int idx, int val) { update(&tree[0], idx, val); }
    void update(Node* root, int idx, int val) {
        if (root->l == root->r) {
            root->max = val;
            return;
        }
        int m = (root->l + root->r) >> 1;
        if (idx <= m) {
            update(root->left, idx, val);
        } else {
            update(root->right, idx, val);
        }
        root->max = max(root->left->max, root->right->max);
    }
    int getMax(int l, int r) {
        ans_max = 0;
        query(&tree[0], l, r);
        return ans_max;
    }
    void query(Node* root, int l, int r) {
        if (root->l == l && root->r == r) {
            if (root->max > ans_max)
                ans_max = root->max;
            return;
        }
        int m = (root->l + root->r) >> 1;
        if (r <= m) {
            query(root->left, l, r);
        } else if (l > m) {
            query(root->right, l, r);
        } else {
            query(root->left, l, m);
            query(root->right, m + 1, r);
        }
    }

private:
    Node* tree;  // tree[0] = root of tree
    int nodeCount;
    int ans_max;
    vector<int> num;
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n_inputs, n_actions, temp;
    cin >> n_inputs >> n_actions;
    vector<int> input(n_inputs);
    for (int i = 0; i < n_inputs; i++) {
        cin >> temp;
        input[i] = temp;
    }
    segmentTree sTree(input);
    int t, a, b;
    for (int i = 0; i < n_actions; i++) {
        cin >> t >> a >> b;
        if (t == 1)
            sTree.update(a - 1, b);
        else if (t == 2)
            cout << sTree.getMax(a - 1, b - 1) << endl;
    }
    return 0;
}