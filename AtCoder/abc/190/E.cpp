#include <bits/stdc++.h>
#include <atcoder/dsu>
using namespace std;

constexpr int inf = 1e9 + 5, mxn = 1e5, mxk = 17;
int n, m, k;
vector<int> adj[mxn];
int c[mxk], dist[mxk][mxk], dp[1 << mxk][mxk];

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n >> m;

    atcoder::dsu d(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        d.merge(a, b);
    }
    cin >> k;
    for (int i = 0; i < k; i++)
        cin >> c[i], --c[i];
    for (int i = 1; i < k; i++) {
        if (!d.same(c[0], c[i])) {
            cout << "-1\n";
            return 0;
        }
    }
    for (int i = 0; i < k; i++) {
        vector<int> D(n, -1), que;
        int s = c[i];
        que.reserve(n);
        que.push_back(s);
        D[s] = 0;
        for (int z = 0; z < int(que.size()); z++) {
            int u = que[z];
            for (int v : adj[u]) {
                if (D[v] == -1) {
                    D[v] = D[u] + 1;
                    que.push_back(v);
                }
            }
        }

        for (int j = 0; j < k; j++)
            dist[i][j] = D[c[j]];
    }

    for (int mask = 1; mask < (1 << k); mask++) {
        if ((mask & (mask - 1)) == 0) {
            dp[mask][__builtin_ctz(mask)] = 1;
            continue;
        }
        for (int i = 0; i < k; i++) {
            if (((mask >> i) & 1) == 0) continue;
            dp[mask][i] = inf;
            for (int j = 0; j < k; j++) {
                if (i == j || !((mask >> j) & 1)) continue;
                dp[mask][i] = min(dp[mask][i], dp[mask ^ (1 << i)][j] + dist[i][j]);
            }
        }
    }
    cout << *min_element(dp[(1 << k) - 1], dp[(1 << k) - 1] + k) << '\n';
    return 0;
}
