#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    int n, m;
    cin >> n >> m;
    string str;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> str;
        for (char c : str)
            a[i] = 2 * a[i] + (c - '0');
    }
    sort(a.begin(), a.end());

    ll target = ((1LL << m) - n - 1) / 2;  // index of the new median
    ll lo = 0LL, hi = (1LL << m) - 1;
    while (lo < hi) {
        ll mid = lo + (hi - lo) / 2;
        // new index of m = m - (# of removed numbers that is less than m)
        ll idx = mid - (lower_bound(a.begin(), a.end(), mid) - a.begin());
        if (idx >= target)
            hi = mid;
        else
            lo = mid + 1;
    }
    // +1 if the answer we found is also removed
    auto it = lower_bound(a.begin(), a.end(), lo);
    while (it != a.end() && *it == lo) {
        lo++, it++;
    }
    // vector<char> ans(m);
    // for (int i = m - 1; i >= 0; i--) {
    //     ans[i] = '0' + (char)(lo & 1LL);
    //     lo >>= 1;
    // }
    // for (char c : ans)
    //     cout << c;
    for (ll i = 1LL << (m - 1); i > 0; i >>= 1) {
        cout << (lo & i ? '1' : '0');
    }
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _n;
    cin >> _n;
    while (_n--) {
        solve();
    }
    return 0;
}