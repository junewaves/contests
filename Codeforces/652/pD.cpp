#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mxn = 2e6 + 1;
const int MOD = 1e9 + 7;
int dp[mxn];
int m_mul(int x, int y) {
    return 1LL * x * y % MOD;
}
int m_add(int x, int y) {
    int res = x + y;
    if (res >= MOD)
        res -= MOD;
    if (res < 0)
        res += MOD;
    return res;
}
int m_add(int x, int y, int tails, ...) {
    return m_add(m_add(x, y), tails);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 3; i < mxn; i++)
        dp[i] = m_add(m_mul(2, dp[i - 2]), dp[i - 1], (i % 3 == 0 ? 4 : 0));
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        cout << dp[n] << '\n';
    }
    return 0;
}