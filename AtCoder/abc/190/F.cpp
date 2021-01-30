#include <bits/stdc++.h>
#include <atcoder/fenwicktree>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n), inv(n);
    atcoder::fenwick_tree<int> ft1(n), ft2(n);
    for (int &it : a) cin >> it;
    int64_t ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        int small = ft1.sum(0, a[i]);
        ans += small;
        inv[i] = n - i - 1 - small * 2;
        ft1.add(a[i], 1);
    }
    cout << ans << '\n';
    for (int i = 0; i < n - 1; i++) {
        ans += inv[i] - (ft2.sum(0, a[i]) * 2 - i);
        ft2.add(a[i], 1);
        cout << ans << '\n';
    }
    return 0;
}
