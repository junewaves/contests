#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(2 * n + 5);
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            a[x]++;
        }
        int ans = 0;
        bool carry = 0;
        for (int i = 0; i <= 2 * n + 1; i++) {
            if (carry) {
                ans++;
                carry = bool(a[i]);
            } else if (a[i] > 0) {
                ans++;
                carry = a[i] > 1;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}