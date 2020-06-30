#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<bool>> a(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
            if (s[j] == '.')
                a[i][j] = true;
    }
    int is, js, ie, je;
    cin >> is >> js >> ie >> je;
    is--, js--, ie--, je--;
    queue<tuple<int, int>> q;
    vector<vector<int>> dis(n, vector<int>(m, 1e9));
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    constexpr int di[4] = {1, 0, -1, 0};
    constexpr int dj[4] = {0, 1, 0, -1};
    q.emplace(is, js);
    dis[is][js] = 0;
    vis[is][js] = true;
    while (!q.empty()) {
        auto [i, j] = q.front();
        q.pop();
        for (int x = 0; x < 4; x++) {
            for (int y = 1; y <= k; y++) {
                int ni = i + di[x] * y, nj = j + dj[x] * y;
                if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                    if (!a[ni][nj] || dis[i][j] + 1 > dis[ni][nj]) {
                        break;
                    } else if (vis[ni][nj]) {
                        continue;
                    } else {
                        vis[ni][nj] = true;
                        dis[ni][nj] = dis[i][j] + 1;
                        q.emplace(ni, nj);
                    }
                } else {
                    break;
                }
            }
        }
    }
    cout << (vis[ie][je] ? dis[ie][je] : -1) << endl;
    return 0;
}