#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    int ans = (a[0][0] != a[n - 1][m - 1]);
    for (int i = 1; i < (n + m - 1) / 2; ++i) {
        int x1 = i, y1 = 0, x2 = m - i - 1, y2 = n - 1;
        if (x1 >= m) {
            y1 += x1 - m + 1;
            x1 = m - 1;
        }
        if (x2 < 0) {
            y2 += x2;
            x2 = 0;
        }
        int c1 = 0, c2 = 0;
        while (x1 >= 0 && y1 < n && x2 < m && y2 >= 0) {
            c1 += a[y1][x1] + a[y2][x2];
            c2 += 2;
            --x1, ++y1;
            ++x2, --y2;
        }
        ans += min(c1, c2 - c1);
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _n;
    cin >> _n;
    while (_n--) {
        solve();
    }
    return 0;
}
