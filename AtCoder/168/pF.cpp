#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int dx[4] = { 0, 1, 0, -1 };
constexpr int dy[4] = { 1, 0, -1, 0 };
constexpr int INF = 0x3f3f3f3f;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<array<int, 3>> a(n), b(m);
    vector<int> x = { -INF, 0, INF }, y = { -INF, 0, INF };
    x.reserve(n + 3);
    y.reserve(m + 3);
    for (int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
        x.push_back(a[i][0]);
        x.push_back(a[i][1]);
        y.push_back(a[i][2]);
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i][0] >> b[i][1] >> b[i][2];
        x.push_back(b[i][0]);
        y.push_back(b[i][1]);
        y.push_back(b[i][2]);
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    x.resize(unique(x.begin(), x.end()) - x.begin());
    y.resize(unique(y.begin(), y.end()) - y.begin());
    int xsize = x.size(), ysize = y.size();
    vector<vector<int>> d(xsize, vector<int>(ysize));
    auto idx = [&](const vector<int>& v, int target) {
        return int(lower_bound(v.begin(), v.end(), target) - v.begin());
    };
    for (const auto& seg : a) {
        int x1 = idx(x, seg[0]);
        int x2 = idx(x, seg[1]);
        int y1 = idx(y, seg[2]);

        for (int j = x1; j < x2; j++) {
            d[j][y1 - 1] |= (1 << 0);
            d[j][y1] |= (1 << 2);
        }
    }
    for (const auto& seg : b) {
        int x1 = idx(x, seg[0]);
        int y1 = idx(y, seg[1]);
        int y2 = idx(y, seg[2]);

        for (int j = y1; j < y2; j++) {
            d[x1 - 1][j] |= (1 << 1);
            d[x1][j] |= (1 << 3);
        }
    }
    queue<pair<int, int>> q;
    vector<vector<bool>> vis(xsize, vector<bool>(ysize, false));
    int sx = idx(x, 0), sy = idx(y, 0);
    q.emplace(sx, sy);
    vis[sx][sy] = 1;
    auto check = [&](int vx, int vy) {
        return vx >= 0 && vx < xsize && vy >= 0 && vy < ysize && !vis[vx][vy];
    };
    while (!q.empty()) {
        int ux, uy;
        tie(ux, uy) = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            if (~d[ux][uy] & (1 << i)) {  // not a fence
                int vx = ux + dx[i];
                int vy = uy + dy[i];
                if (check(vx, vy)) {
                    q.emplace(vx, vy);
                    vis[vx][vy] = true;
                }
            }
        }
    }

    for (int i = 0; i < ysize; i++) {
        if (vis[0][i] || vis[xsize - 1][i]) {
            cout << "INF\n";
            return 0;
        }
    }
    for (int i = 0; i < xsize; i++) {
        if (vis[i][0] || vis[i][ysize - 1]) {
            cout << "INF\n";
            return 0;
        }
    }

    ll ans = 0;
    for (int i = 0; i < xsize; i++) {
        for (int j = 0; j < ysize; j++) {
            if (vis[i][j]) {
                ans += 1LL * (x[i + 1] - x[i]) * (y[j + 1] - y[j]);
            }
        }
    }
    cout << ans << '\n';
    return 0;
}