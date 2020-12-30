#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, m;
        cin >> n >> m;
        vector<string> a(n);
        for (auto &it : a) cin >> it;
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        int ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (a[i][j] == '*') {
                    if (j - 1 >= 0)
                        dp[i][j] = min({dp[i+1][j-1], dp[i+1][j], dp[i+1][j+1]}) + 1;
                    else
                        dp[i][j] = 1;
                    ans += dp[i][j];
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}