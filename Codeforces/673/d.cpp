#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int sum = accumulate(a.begin(), a.end(), 0);
    if (sum % n != 0) {
        cout << "-1\n";
        return;
    }
    int target = sum / n;
    vector<array<int, 3>> ans;
    for (int i = 2; i <= n; i++) {
        // all move to 1
        if (a[i] % i != 0) {
            int need = i - (a[i] % i);
            a[i] += need;
            ans.push_back({1, i, need});
        }
        ans.push_back({i, 1, a[i] / i});
    }
    for (int i = 2; i <= n; i++) {
        ans.push_back({1, i, target});
    }
    cout << ans.size() << '\n';
    for (auto it : ans) {
        for (int j : it)
            cout << j << ' ';
        cout << '\n';
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