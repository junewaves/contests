#include <bits/stdc++.h>
using namespace std;

constexpr int mxn = 2e5 + 1;
int cnt[mxn], dp[mxn];
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            cnt[x]++;
        }
        int max_len = 0;
        for (int i = mxn - 1; i > 0; i--) {
            dp[i] = cnt[i];
            for (int j = i * 2; j < mxn; j += i)
                dp[i] = max(dp[i], cnt[i] + dp[j]);
            max_len = max(max_len, dp[i]);
        }
        cout << n - max_len << '\n';
    }
    return 0;
}
