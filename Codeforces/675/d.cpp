#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
using point = pair<int64_t, int64_t>;
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    point s, e;
    cin >> s.x >> s.y >> e.x >> e.y;
    vector<point> ins(m);
    vector<vector<int>> order(2, vector<int>(m));
    for (int i = 0; i < m; i++) {
        cin >> ins[i].x >> ins[i].y;
        order[0][i] = i;
        order[1][i] = i;
    }
    sort(order[0].begin(), order[0].end(), [&](int a, int b) {
        return ins[a].x < ins[b].x;
    });
    sort(order[1].begin(), order[1].end(), [&](int a, int b) {
        return ins[a].y < ins[b].y;
    });
    auto getdist = [](point a, point b, bool instant) -> int64_t {
        if (instant)
            return min(abs(a.x - b.x), abs(a.y - b.y));
        else
            return abs(a.x - b.x) + abs(a.y - b.y);
    };
    const int s_id = m, e_id = m + 1;
    vector<vector<pair<int, int64_t>>> adj(m + 2);
    for (int i = 0; i < m; i++)
        adj[s_id].emplace_back(i, getdist(s, ins[i], true));
    adj[s_id].emplace_back(e_id, getdist(s, e, false));
    for (int d = 0; d < 2; d++) {
        for (int i = 0; i < m; i++) {
            int cur = order[d][i];
            if (i > 0) {
                int prv = order[d][i - 1];
                adj[cur].emplace_back(prv, getdist(ins[cur], ins[prv], true));
            }
            if (i + 1 < m) {
                int nxt = order[d][i + 1];
                adj[cur].emplace_back(nxt, getdist(ins[cur], ins[nxt], true));
            }
        }
    }
    for (int i = 0; i < m; i++)
        adj[i].emplace_back(e_id, getdist(ins[i], e, false));
    vector<int64_t> dist(m + 2, 4e18);
    dist[s_id] = 0;
    priority_queue<pair<int64_t, int>, vector<pair<int64_t, int>>, greater<>> pq;
    pq.emplace(0, s_id);
    while (!pq.empty()) {
        auto [d, id] = pq.top();
        pq.pop();
        if (d != dist[id]) continue;
        for (auto [nxt, nd] : adj[id]) {
            nd += d;
            if (dist[nxt] > nd) {
                dist[nxt] = nd;
                pq.emplace(nd, nxt);
            }
        }
    }
    cout << dist[e_id] << '\n';
    return 0;
}