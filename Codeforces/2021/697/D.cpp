#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n), b(n);
        for (int &it : a) cin >> it;
        for (int &it : b) cin >> it;
        if (accumulate(a.begin(), a.end(), 0LL) < m) {
            cout << "-1\n";
            continue;
        }
        vector<int64_t> v1, v2;
        for (int i = 0; i < n; i++)
            (b[i] == 1 ? v1 : v2).push_back(a[i]);
        sort(v1.rbegin(), v1.rend());
        sort(v2.rbegin(), v2.rend());
        for (int i = 1; i < int(v2.size()); i++)
            v2[i] += v2[i - 1];
        int sum = 0, lim = v2.size(), ans = INT_MAX;
        int j = lower_bound(v2.begin(), v2.end(), m) - v2.begin();
        if (j < lim) ans = min(ans, (j + 1) * 2);
        for (int i = 0; i < int(v1.size()); i++) {
            sum += v1[i];
            if (sum < m) {
                j = lower_bound(v2.begin(), v2.end(), m - sum) - v2.begin();
                if (j < lim) ans = min(ans, i + 1 + (j + 1) * 2);
            } else {
                ans = min(ans, i + 1);
                break;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
