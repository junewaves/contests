#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    int64_t C;
    cin >> n >> C;
    vector<pair<int, int>> a;
    for (int i = 0; i < n; i++) {
        int l, r, c;
        cin >> l >> r >> c;
        a.emplace_back(l, c);
        a.emplace_back(r + 1, -c);
    }
    sort(a.begin(), a.end());
    int64_t cost = 0;
    int64_t ans = 0;
    int last = 0;
    for (auto [d, c] : a) {
        ans += min(cost, C) * (d - last);
        cost += c;
        last = d;
    }
    cout << ans << '\n';
    return 0;
}