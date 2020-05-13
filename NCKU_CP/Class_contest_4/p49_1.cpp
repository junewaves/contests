#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
int n, m, a[80][2];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    vector<int> dp(m + 1);
    iota(dp.begin(), dp.end(), 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1];
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < n; j++) {
            int x = a[j][0], s = a[j][1];
            if (i > x + s)
                dp[i] = min(dp[i], dp[max(0, x + x - i - 1)] + i - (x + s));
            else
                dp[i] = min(dp[i], dp[max(0, x - s - 1)]);
        }
    }
    cout << dp[m] << endl;
    return 0;
}