#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n), c(n);
        for (auto& it : c) cin >> it;
        for (auto& it : a) cin >> it;
        for (auto& it : b) cin >> it;

        int64_t ans = 0, carry = 0;
        for (int i = 1; i < n; i++) {
            if (a[i] == b[i]) {
                carry = 2;
            } else {
                if (a[i] > b[i])
                    swap(a[i], b[i]);
                if (i > 1)
                    carry += a[i] - 1 + c[i-1] - b[i] + 2;
                carry = max(carry, b[i] - a[i] + 2LL);
            }
            ans = max(ans, carry + c[i] - 1);
        }
        cout << ans << '\n';
    }
    return 0;
}
