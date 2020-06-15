#include <bits/stdc++.h>
using namespace std;

struct Node {
    int id, w;
    Node(int x, int y) : id(x), w(y) {}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<Node>> adj(n);
    // map<pair<int, int>, int> relax;
    for (int i = 0, u, v, w; i < m; i++) {
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        // relax[make_pair(u, v)] = 0;
    }
    queue<int> q;
    vector<int> s(n, INT_MAX), cnt(n, 0);
    vector<bool> inq(n, false);
    bool ok = true;
    q.push(0);
    s[0] = 0;
    inq[0] = true;
    while(!q.empty() && ok) {
        int u = q.front();
        q.pop();
        inq[u] = false;
        for (const Node& v : adj[u]) {
            if (s[v.id] > s[u] + v.w) {
                s[v.id] = s[u] + v.w;
                if (++cnt[v.id] >= n) {
                    ok = false;
                    break;
                }
                if (!inq[v.id]) {
                    q.push(v.id);
                    inq[v.id] = true;
                }
            }
        }
    }
    /*
    for (auto& e : adj) {
        for (auto& i : e) {
            cout << i.id << " " << i.w << '\n';
        }
    }
    for (int i : s)
        cout << i << ' ';
    cout << '\n';*/
    if (!ok)
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}
