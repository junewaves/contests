#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int di[4] = { -1, 0, 1, 0 };
const int dj[4] = { 0, -1, 0, 1 };
int main() {
    int n;
    cin >> n;
    vector<int> a(n * n);
    vector<vector<int>> dist(n, vector<int>(n));
    vector<vector<int>> exist(n, vector<int>(n, 1));
    for (int i = 0, x = 0, y = 0; i < n * n; i++, y = (y + 1) % n) {
        cin >> a[i];
        a[i]--;
        dist[x][y] = min({ x, y, n - x - 1, n - y - 1 });
        if ((i + 1) % n == 0) {
            x++;
        }
    }
    // queue<pair<int, int>> q;
    vector<pair<int, int>> q;
    vector<vector<bool>> inq(n, vector<bool>(n));
    int ans = 0;
    for (int id : a) {
        int i = id / n, j = id % n;
        ans += dist[i][j];
        exist[i][j] = 0;
        // q.emplace(i, j);
        q.clear();
        q.emplace_back(i, j);
        // while (!q.empty()) {
        for (int k = 0; k < (int)q.size(); k++) {
            // int mi, mj;
            // tie(mi, mj) = q.front();
            int mi = q[k].first;
            int mj = q[k].second;
            // q.pop();
            inq[mi][mj] = false;
            int val = dist[mi][mj] + exist[mi][mj];
            for (int d = 0; d < 4; d++) {
                int ni = mi + di[d], nj = mj + dj[d];
                if (ni >= 0 && nj >= 0 && ni < n && nj < n &&
                    val < dist[ni][nj]) {
                    dist[ni][nj] = val;
                    if (!inq[ni][nj]) {
                        q.emplace_back(ni, nj);
                        inq[ni][nj] = true;
                    }
                }
            }
        }
    }
    cout << ans << '\n';
}
