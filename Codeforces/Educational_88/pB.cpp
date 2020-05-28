#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vector<vector<bool>> b(n, vector<bool>(m, 0));
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            if (s[j] == '.') {
                b[i][j] = 1;
                cnt++;
            }
        }
    }
    if (x * 2 <= y) {
        cout << cnt * x << '\n';
        return;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (b[i][j]) {
                b[i][j] = 0;
                if (j + 1 < m && b[i][j + 1]) {
                    b[i][j + 1] = 0;
                    ans += y;
                } else {
                    ans += x;
                }
            }
        }
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
