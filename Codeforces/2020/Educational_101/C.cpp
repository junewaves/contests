#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k;
        cin >> n >> k;
        vector<int64_t> h(n);
        for (auto &it : h) cin >> it;
        int64_t mn = h[0], mx = mn + k;
        bool ok = true;
        for (int i = 1; i < n - 1; i++) {
            if (h[i] + 2 * k - 1 > mn && mx > h[i]) {
                mn = max(mn - k + 1, h[i]);
                mx = min(mx + k - 1, h[i] + 2 * k - 1);
            } else {
                ok = false;
                break;
            }
        }
        if (ok && h[n - 1] + k > mn && mx > h[n - 1])
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}