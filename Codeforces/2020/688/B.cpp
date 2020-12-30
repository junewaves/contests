#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &it : a) cin >> it;
        int64_t sum = 0;
        for (int i = 1; i < n; i++)
            sum += abs(a[i] - a[i - 1]);
        int64_t ans = sum;
        for (int i = 0; i < n; i++) {
            int64_t save = 0;
            if (i > 0) save += abs(a[i] - a[i - 1]);
            if (i + 1 < n) save += abs(a[i + 1] - a[i]);
            if (i > 0 && i + 1 < n) save -= abs(a[i - 1] - a[i + 1]);
            ans = min(ans, sum - save);
        }
        cout << ans << '\n';
    }
    return 0;
}