#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
    bool operator<(const Edge& o) const { return w < o.w; }
};

vector<int> group;

int Find(int u) {
    if (group[u] == u)
        return u;
    return group[u] = Find(group[u]);
}

void Union(int u, int v) {
    group[Find(u)] = Find(v);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    while (1) {
        cin >> n >> m;
        if (n == 0 && m == 0)
            break;
        group = vector<int>(n);
        for (int i = 0; i < n; i++)
            group[i] = i;
        vector<Edge> E(m);
        for (Edge& e : E)
            cin >> e.u >> e.v >> e.w, --e.u, --e.v;
        sort(E.begin(), E.end());
        int ans = 0, con = 0;
        for (const Edge& e : E) {
            if (Find(e.u) != Find(e.v)) {
                Union(e.u, e.v);
                ans += e.w;
                ++con;
            }
        }
        cout << (con == n - 1 ? ans : -1) << '\n';
    }
    return 0;
}
