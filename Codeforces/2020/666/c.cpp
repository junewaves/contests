#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int64_t> a(n);
    for (int64_t& it : a)
        cin >> it;
    if (n == 1) {
        for (int i = 0; i < 3; i++) {
            cout << "1 1\n";
            cout << a[0] * -1 << "\n";
            a[0] = 0;
        }
        return;
    }
    cout << "1 " << n - 1 << '\n';
    for (int i = 0; i < n - 1; i++) {
        int64_t diff = a[i] % n;
        cout << diff * (n - 1) << ' ';
        a[i] += diff * (n - 1);
    }
    cout << '\n';
    cout << n << ' ' << n << '\n';
    cout << -(a[n - 1] % n) << '\n';
    a[n - 1] -= a[n - 1] % n;
    cout << "1 " << n << '\n';
    for (int64_t it : a) cout << -it << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    while (tt--)
        solve();
    return 0;
}