#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int &it : a) cin >> it;
    for (int &it : b) cin >> it;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++)
        dp[i][0] = i;
    for (int j = 1; j <= m; j++)
        dp[0][j] = j;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i] == b[j])
                dp[i+1][j+1] = dp[i][j];
            else
                dp[i+1][j+1] = min({dp[i][j], dp[i+1][j], dp[i][j+1]}) + 1;
        }
    }
    cout << dp[n][m] << '\n';
}
