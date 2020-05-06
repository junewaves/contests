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
    // unordered_map<int, ll> mp;
    // vector<vector<int>> tmp(n, vector<int>(3));
    // vector<int> s;
    // s.reserve(2 * n);
    vector<pair<int, int>> s;
    for (int i = 0; i < n; i++) {
        int l, r, w;
        cin >> l >> r >> w;
        s.emplace_back(l, w);
        s.emplace_back(r, -w);
    }
    sort(s.begin(), s.end());
    // for (auto p : s)
    //     cout << p.first << ", " << p.second << endl;
    // s.resize(unique(s.begin(), s.end()) - s.begin());
    // cout << s.size() << endl;
    // exit(0);
    // vector<int> mp(s.size() + 1, 0);
    // for (const auto& v : tmp) {
    //     int l = lower_bound(s.begin(), s.end(), v[0]) - s.begin();
    //     int r = lower_bound(s.begin(), s.end(), v[1]) - s.begin();
    //     mp[l] += v[2];
    //     mp[r] -= v[2];
    // }
    ll ans = 0, p = 0;
    for (const auto& pp : s) {
        p += pp.second;
        ans = max(ans, p);
    }
    cout << ans << '\n';
}
