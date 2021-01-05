#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, m;
        cin >> n >> m;
        vector<int> k(n), c(m);
        for (int &it : k) cin >> it, it--;
        for (int &it : c) cin >> it;
        sort(k.rbegin(), k.rend());
        int64_t ans = 0;
        int j = 0;
        for (int i : k) {
            if (j >= m || j >= i) ans += c[i];
            else ans += c[j++];
        }
        cout << ans << '\n';
    }
    return 0;
}