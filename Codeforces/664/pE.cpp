#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifdef _LOCAL_DEBUG
#include "templates/debug.h"
#else
#define debug(...)
#endif

constexpr int mxn = 2e5 + 5;
int n, m, k, cnt[10][10];
bool bad[10][10], bad_pairs[10][10][10][10];
vector<pair<int, int>> out[mxn], in[mxn];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        out[u].emplace_back(w, v);
    }
    for (int i = 1; i <= n; i++) {
        sort(out[i].begin(), out[i].end());
        int degree = out[i].size();
        for (int j = 0; j < degree; j++)
            in[out[i][j].second].emplace_back(degree, j + 1);
    }
    for (int u = 1; u <= n; u++) {
        int c[10][10] = {};
        for (const auto& p : in[u]) c[p.first][p.second]++;
        for (int i = 1; i <= k; i++) {
            for (int j = 1; j <= k; j++) {
                if (c[i][j] > 1) {
                    bad[i][j] = true;
                } else if (c[i][j] == 1) {
                    cnt[i][j]++;
                    for (int x = i + 1; x <= k; x++)
                        for (int y = 1; y <= x; y++)
                            if (c[x][y] == 1)
                                bad_pairs[i][j][x][y] = true;
                }
            }
        }
    }
    int all = 1, ans = 0;
    for (int i = 2; i <= k; i++)
        all *= i;
    for (int idx = 0; idx < all; idx++) {
        int sum = 0, cur_idx = idx;
        bool ok = true, became_bad[10][10] = {};
        for (int i = 1, j; i <= k; i++) {
            j = (cur_idx % i) + 1;
            cur_idx /= i;
            if (bad[i][j] || became_bad[i][j]) {
                ok = false;
                break;
            }
            sum += cnt[i][j];
            for (int x = i + 1; x <= k; x++)
                for (int y = 1; y <= x; y++)
                    became_bad[x][y] |= bad_pairs[i][j][x][y];
        }
        if (ok && sum == n)
            ans++;
    }
    cout << ans << '\n';
    return 0;
}