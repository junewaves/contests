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
        sort(a.begin(), a.end());
        int64_t ans = 0;
        for (int i = 0, j = 0; i < n - 2; i++) {
            if (j < i) j = i;
            while (j + 1 < n && a[j + 1] - a[i] <= 2) j++;
            if (int64_t x = j - i; x >= 3 - 1)
                ans += x * (x - 1) / 2;
        }
        cout << ans << '\n';
    }
    return 0;
}