// Kickstart 2020 Round B (4/19)
#include <bits/stdc++.h>
using namespace std;
#ifndef _VSCODE_DEBUG
#define endl '\n'
#endif
typedef long long ll;
int W, H, L, U, R, D;
void solve() {
    cin >> W >> H >> L >> U >> R >> D;
    if (W == R - L + 1 || H == D - U + 1) {
        cout << 0 << endl;
        return;
    }
    vector<vector<double>> dp(H, vector<double>(W, 0.0));
    ll fail = 0;
    auto is_hole = [&](int i, int j) {
        return i + 1 >= U && i < D && j + 1 >= L && j < R;
    };
    dp[0][0] = 1.0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (!is_hole(i, j)) {
                if (i == H - 1 && j < W - 1)
                    dp[i][j + 1] += dp[i][j];
                else if (j == W - 1 && i < H - 1)
                    dp[i + 1][j] += dp[i][j];
                else if (!(i == H - 1 && j == W - 1)) {
                    if (!is_hole(i + 1, j))
                        dp[i + 1][j] += 0.5 * dp[i][j];
                    if (!is_hole(i, j + 1))
                        dp[i][j + 1] += 0.5 * dp[i][j];
                }
            }
        }
    }
    cout << dp[H - 1][W - 1] << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _n;
    cin >> _n;
    for (int i = 1; i <= _n; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
}
