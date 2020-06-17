#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int mxA = 200;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<vector<int>> cnt(mxA, vector<int>(n + 1)), pos(mxA);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < mxA; j++) {
            cnt[j][i + 1] = cnt[j][i];
        }
        cin >> a[i];
        ++cnt[a[i] - 1][i + 1];
        pos[a[i] - 1].push_back(i);
    }
    int ans = 0;
    for (int i = 0; i < mxA; i++) {
        int m = pos[i].size();
        ans = max(ans, m);
        for (int j = 0; j < m / 2; j++) {
            int l = pos[i][j] + 1, r = pos[i][m - j - 1];
            for (int k = 0; k < mxA; k++)
                ans = max(ans, (j + 1) * 2 + (cnt[k][r] - cnt[k][l]));
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