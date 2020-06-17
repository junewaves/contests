#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0, t; i < n; i++) {
        cin >> t;
        a[--t]++;
    }
    int cnt = 0, mxt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > 0) {
            cnt++;
            mxt = max(mxt, a[i]);
        }
    }
    if (cnt >= mxt)
        cnt--;
    cout << min(mxt, cnt) << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _cn;
    cin >> _cn;
    while (_cn--) {
        solve();
    }

    return 0;
}