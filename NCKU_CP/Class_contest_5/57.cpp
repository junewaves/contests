#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Edge {
    int u, v, w;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, m;
    cin >> n >> m;
    vector<Edge> E(m);
    vector<int> s(n, 0x3f3f3f3f);
    s[0] = 0;
    for (Edge& e : E) {
        cin >> e.u >> e.v >> e.w;
    }
    for (int i = 1; i < n; i++) {
        for (const Edge& e : E) {
            s[e.v] = min(s[e.v], s[e.u] + e.w);
        }
    }
    bool ok = true;
    for (const Edge& e : E) {
        if (s[e.v] > s[e.u] + e.w) {
            ok = false;
            break;
        }
    }
    cout << (ok ? "No" : "Yes") << '\n';
    return 0;
}
