#include <bits/stdc++.h>
#ifndef _LOCAL_DEBUG
#define endl '\n'
#endif
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> s;
    s.reserve(n << 1);
    for (int i = 0; i < n; i++) {
        int l, r, w;
        cin >> l >> r >> w;
        s.emplace_back(l, w);
        s.emplace_back(r, -w);
    }
    sort(s.begin(), s.end());
    ll ans = 0, sum = 0;
    for (const auto& p : s) {
        sum += p.second;
        ans = max(ans, sum);
    }
    cout << ans << endl;
}
