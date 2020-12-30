#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &it : a)
        cin >> it;
    int cnt = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] != a[i - 1])
            cnt++;
    }
    if (cnt > 0 && k == 1) {
        cout << -1 << '\n';
    } else {
        int m = 1;
        while ((cnt + m - 1) / m > k - 1) m++;
        cout << m << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}