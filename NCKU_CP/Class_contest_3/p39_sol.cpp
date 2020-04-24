#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k, tmp;
    cin >> n >> k;
    if (k == 1) {
        puts("0");
        return 0;
    }
    vector<ll> sum(n);
    vector<ll> dp(n);
    deque<pair<ll, int>> q;
    cin >> tmp;
    sum[0] = tmp;
    dp[0] = tmp;
    q.emplace_back(sum[0], 0);
    for (int i = 1; i < k - 1; i++) {
        cin >> tmp;
        sum[i] = sum[i - 1] + tmp;
        dp[i] = sum[i];
        ll s = sum[i] - dp[i - 1];
        while (!q.empty() && s < q.back().first)
            q.pop_back();
        q.emplace_back(s, i);
    }
    q.emplace_back(dp[k - 2], k - 2);
    for (int i = k - 1; i < n; i++) {
        cin >> tmp;
        sum[i] = sum[i - 1] + tmp;
        ll s = sum[i] - dp[i - 1];
        while (!q.empty() && s < q.back().first)
            q.pop_back();
        q.emplace_back(s, i);
        dp[i] = sum[i] - q.front().first;
        if (q.front().second == i - k + 1)
            q.pop_front();
    }
    cout << dp[n - 1] << '\n';
}