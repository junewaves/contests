#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int cnt = 0, r = -1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt += a[i];
        if (a[i] == 1)
            r = i;
    }
    if (cnt == 1) {
        cout << "0\n";
        return;
    }
    int ans = 0;
    for (int i = 0, j = 0; i < n; i++) {
        if (a[i] == 1) {
            j = max(j, i + 1);
            while (j < r && a[j] != 0) j++;
            if (j < r) {
                swap(a[i], a[j]);
                ans++;
            } else {
                break;
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}