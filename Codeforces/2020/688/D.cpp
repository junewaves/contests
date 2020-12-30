#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int64_t k;
        cin >> k;
        if (k % 2 == 1) {
            cout << "-1\n";
            continue;
        }
        string ans;
        for (int i = 1; (k >> i) > 0; i++) {
            if ((k >> i) & 1) {
                ans += "1 ";
                if (i > 1) {
                    for (int j = 0; j < i - 2; j++)
                        ans += "0 ";
                    ans += "1 ";
                }
            }
        }
        assert((int)ans.size() <= 2 * 2000);
        cout << ans.size() / 2 << '\n';
        cout << ans << '\n';
    }
    return 0;
}