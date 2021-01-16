#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using mint = atcoder::modint998244353;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> g(n, string(m, '?'));
    for (int i = 0; i < k; i++) {
        int h, w;
        char c;
        cin >> h >> w >> c;
        --h, --w;
        g[h][w] = c;
    }
    vector<vector<mint>> dp(n + 1, vector<mint>(m + 1));
    dp[0][0] = 1;
    mint z = mint(2) / 3;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            mint add = dp[i][j];
            switch (g[i][j]) {
              case 'R':
                dp[i][j+1] += add;
                break;
              case 'D':
                dp[i+1][j] += add;
                break;
              case '?':
                add *= z;
                // fallthrough
              case 'X':
                dp[i+1][j] += add;
                dp[i][j+1] += add;
            }
        }
    }
    cout << (dp[n-1][m-1] * mint(3).pow(n * m - k)).val() << '\n';
    return 0;
}
