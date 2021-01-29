#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k;
        cin >> n >> k;
        vector<int64_t> p(n);
        for (auto &it : p) cin >> it;

        int64_t sum = p[0], ans = 0;
        for (int i = 1; i < n; i++) {
            int64_t diff = p[i] * 100 - sum * k;
            if (diff > 0) {
                int64_t increase = (diff + k - 1) / k;
                ans += increase;
                sum += increase;
            }
            sum += p[i];
        }

        cout << ans << '\n';
    }
    return 0;
}
