#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
int n, m, t;
vector<pair<int, int>> dir = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
vector<vector<bool>> chg;
vector<vector<int>> dis;
vector<pair<int, int>> pnt;

void dfs(int i, int j, int d) {
    if (d >= dis[i][j] && dis[i][j] != -1)
        return;
    dis[i][j] = d;
    for (auto& p : dir) {
        int x = i + p.first, y = j + p.second;
        if (x >= 0 && x < n && y >= 0 && y < m && !chg[x][y]) {
            dfs(x, y, d + 1);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> t;
    vector<string> a(n);
    chg.resize(n, vector<bool>(m));
    dis.resize(n, vector<int>(m, -1));
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (auto& p : dir) {
                int x = i + p.first, y = j + p.second;
                if (x >= 0 && x < n && y >= 0 && y < m && a[i][j] == a[x][y]) {
                    chg[i][j] = true;
                }
            }
            if (chg[i][j]) {
                q.emplace(i, j);
                dis[i][j] = 0;
            }
        }
    }
    while (!q.empty()) {
        int i, j, d;
        tie(i, j) = q.front();
        d = dis[i][j];
        q.pop();
        for (const auto& p : dir) {
            int x = i + p.first, y = j + p.second;
            if (x >= 0 && x < n && y >= 0 && y < m && dis[x][y] == -1) {
                dis[x][y] = d + 1;
                q.emplace(x, y);
            }
        }
    }
    int x, y;
    ll k;
    for (int i = 0; i < t; i++) {
        cin >> x >> y >> k;
        --x, --y;
        if (dis[x][y] == -1) {
            cout << a[x][y] << endl;
            continue;
        }
        ll change = max(k - (ll)dis[x][y], 0LL);
        if (change & 1LL)
            cout << (a[x][y] == '0' ? '1' : '0') << endl;
        else
            cout << a[x][y] << endl;
    }
    return 0;
}
