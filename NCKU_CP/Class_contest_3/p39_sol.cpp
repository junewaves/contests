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
    ll sum_i, dp_i;
    cin >> dp_i;
    sum_i = dp_i;
    deque<pair<ll, int>> q;
    q.emplace_back(dp_i, 0);
    for (int i = 1; i < k - 1; i++) {
        cin >> tmp;
        sum_i += tmp;
        ll s = sum_i - dp_i;
        while (!q.empty() && s < q.back().first)
            q.pop_back();
        q.emplace_back(s, i);
        dp_i = sum_i;
    }
    for (int i = k - 1; i < n; i++) {
        cin >> tmp;
        sum_i += tmp;
        ll s = sum_i - dp_i;
        while (!q.empty() && s < q.back().first)
            q.pop_back();
        q.emplace_back(s, i);
        dp_i = sum_i - q.front().first;
        if (q.front().second == i - k + 1)
            q.pop_front();
    }
    cout << dp_i << '\n';
}