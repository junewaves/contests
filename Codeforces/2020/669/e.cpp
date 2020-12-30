#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<array<vector<int>, 2>> rev(n); // reverse adj list
    vector<int> banned(n, -1);
    for (int i = 0; i < m; i++) {
        int u, v, type;
        cin >> u >> v >> type;
        --u, --v;
        rev[v][type].push_back(u);
    }
    // run bfs from target to source
    vector<int> dis(n, n);
    vector<int> q = {n - 1};
    dis[n - 1] = 0;
    for (int index = 0; index < (int)q.size(); index++) {
        int u = q[index];
        for (int t : {0, 1}) {
            for (int v : rev[u][t]) {
                // delete all outgoing edge of type t (which is closest to target)
                if (banned[v] == -1) banned[v] = t;
                // if v has both outgoing edge of type 0 and 1,
                // update v's distance to target
                if (banned[v] != t && dis[v] > dis[u] + 1) {
                    dis[v] = dis[u] + 1;
                    q.push_back(v);
                }
            }
        }
    }
    cout << (dis[0] == n ? -1 : dis[0]) << '\n';
    for (int b : banned) 
        cout << ((b & 1) ^ 1); 
    cout << '\n';
    return 0;
}