#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int ans = n + 5;
        vector<int> suf(n);
        for (int i = n - 1; i >= 0; i--) {
            if (i > 0)
                suf[i - 1] = suf[i] + int(s[i] == '0');
            else
                ans = suf[i] + int(s[i] == '0');
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            ans = min(ans, cnt + suf[i]);
            cnt += int(s[i] == '1');
        }
        cout << ans << '\n';
    }
    return 0;
}
