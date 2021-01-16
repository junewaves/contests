#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int64_t> a(n), b(n);
    for (auto &it : a) cin >> it;
    for (auto &it : b) cin >> it;
    int64_t mxa = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        mxa = max(mxa, a[i]);
        ans = max(ans, mxa * b[i]);
        cout << ans << '\n';
    }
    return 0;
}
