#include <bits/stdc++.h>
using namespace std;

constexpr int INF = 2e9;

// struct Edge {  // for Bellman-Ford’s Algorithm
//     int u, v;
//     Edge(int a, int b) : u(a), v(b) {}
// };

bool solve() {
    static int cn = 0;
    int n, s, x, y;
    cin >> n;
    if (!n)
        return false;
    cin >> s;  // source point
    // vector<Edge> E;  // for Bellman-Ford’s Algorithm
    vector<vector<int>> adj(n + 1);  // for SPFA
    while (1) {
        cin >> x >> y;
        if (x == 0 && y == 0)
            break;
        // E.emplace_back(x, y);
        adj[x].push_back(y);
    }
    vector<int> d(n + 1, -INF);
    d[s] = 0;
    //  Bellman-Ford’s Algorithm
    // for (int i = 1; i < n; i++) {
    //     for (const Edge& e : E) {
    //         if (e.v == s)
    //             continue;
    //         d[e.v] = max(d[e.v], d[e.u] + 1);
    //     }
    // }
    // SPFA
    queue<int> q;
    vector<bool> inq(n + 1, false);
    q.push(s);
    inq[s] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        inq[u] = false;
        for (int v : adj[u]) {
            if (d[v] < d[u] + 1) {
                d[v] = d[u] + 1;
                if (!inq[v]) {
                    q.push(v);
                    inq[v] = true;
                }
            }
        }
    }
    int maxd = -INF, maxp = 0;
    for (int i = 1; i <= n; i++) {
        if (d[i] > maxd) {
            maxd = d[i];
            maxp = i;
        }
    }
    cout << "Case " << ++cn << ": ";
    cout << "The longest path from " << s << " has length " << maxd;
    cout << ", finishing at " << maxp << ".\n\n";
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (solve()) {}
}
