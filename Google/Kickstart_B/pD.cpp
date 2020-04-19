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
    vector<vector<ll>> dp(H, vector<ll>(W, 0));
    ll fail = 0;
    auto is_hole = [&](int i, int j) {
        return i + 1 >= U && i < D && j + 1 >= L && j < R;
    };
    for (int i = 0; i < H; i++)
        dp[i][0] = 1;
    for (int j = 0; j < W; j++)
        dp[0][j] = 1;
    for (int i = 1; i < H; i++) {
        for (int j = 1; j < W; j++) {
            ll u = dp[i - 1][j] + dp[i][j - 1];
            // u += is_hole(i - 1, j) ? 0 : dp[i - 1][j];
            // u += is_hole(i, j - 1) ? 0 : dp[i][j - 1];
            if (is_hole(i, j))
                fail += u;

            dp[i][j] = u;
        }
    }
    double t = fail + dp[H - 1][W - 1];
    double p = (double)fail / dp[H - 1][W - 1];
    cout << fixed << setprecision(10) << 1 - p << endl;
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
