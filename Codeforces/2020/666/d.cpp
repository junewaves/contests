#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& it : a)
        cin >> it;
    if (n == 1) {
        cout << "T\n";
        return;
    }
    int mx = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        mx = max(mx, a[i]);
    }
    if (mx > sum - mx) {
        cout << "T\n";
        return;
    }
    cout << (sum % 2 ? "T\n" : "HL\n");
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}