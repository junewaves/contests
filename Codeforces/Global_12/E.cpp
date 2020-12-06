#include <bits/stdc++.h>
using namespace std;

template<class Fun>
class y_combinator_result {
    Fun fun_;

public:
    template<class T>
    explicit y_combinator_result(T&& fun) : fun_(std::forward<T>(fun)) {}

    template<class... Args>
    decltype(auto) operator()(Args&&... args) {
        return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
};

template<class Fun>
decltype(auto) y_combinator(Fun&& fun) {
    return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    if (n == 1) {
        cout << "YES\n0\n0\n";
        return 0;
    }
    vector<vector<int>> adj(n);
    vector<vector<int>> dist(n, vector<int>(n, int(1e9)));
    vector<int> deg(n);
    for (int i = 0; i < n; i++)
        dist[i][i] = 0;
    for (int i = 0; i < m; i++) {
        int u, v, dir;
        cin >> u >> v >> dir;
        --u, --v;
        if (dir) {
            adj[u].push_back(v);
            deg[v]++;
            dist[u][v] = 1;
            dist[v][u] = -1;
        } else {
            adj[u].push_back(v);
            adj[v].push_back(u);
            deg[u]++;
            deg[v]++;
            dist[u][v] = 1;
            dist[v][u] = 1;
        }
    }
    int start = min_element(deg.begin(), deg.end()) - deg.begin();
    vector<int> color(n, 0);
    auto bipartite = y_combinator([&](auto dfs, int u, int p, int c) -> bool {
        color[u] = c;
        for (int v : adj[u]) {
            if (v == p) continue;
            if (color[v] == 0) {
                if (!dfs(v, u, 3 - c)) 
                    return false;
            } else if (color[v] == c) {
                return false;
            }
        }
        return true;
    })(start, -1, 1);
    if (!bipartite) {
        cout << "NO\n";
        return 0;
    }
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    cout << "NO\n";
                    return 0;
                }
    int max_dist = 0;
    int u = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                if (dist[i][j] > max_dist) {
                    max_dist = dist[i][j];
                    u = i;
                }
                max_dist = max(max_dist, dist[i][j]);
            }
        }
    }
    assert(u >= 0);
    cout << "YES\n";
    cout << max_dist << '\n';
    for (int i = 0; i < n; i++)
        cout << dist[u][i] << ' ';
    cout << endl;
    return 0;
}