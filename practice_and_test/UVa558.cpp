#include <bits/stdc++.h>
using namespace std;

constexpr int INF = 2e9;

struct Edge {
    int u, v, w;
    bool operator<(const Edge& o) const { return w > o.w; }  // make min heap
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<Edge> E(m);
    vector<int> S(n, INF);
    for (Edge& e : E)
        cin >> e.u >> e.v >> e.w;
    S[0] = 0;
    for (int i = 1; i < n; i++) {
        for (const Edge& e : E) {
            S[e.v] = min(S[e.v], S[e.u] + e.w);
        }
    }
    bool ok = false;
    for (const Edge& e : E) {
        if (S[e.v] > S[e.u] + e.w) {
            ok = true;
            break;
        }
    }
    if (!ok)
        cout << "not ";
    cout << "possible\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
