#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &it : a) cin >> it;
    sort(a.begin(), a.end());
    int64_t ans = 0;
    for (int i = 1; i < n; i++)
        ans += int64_t(a[i] - a[i - 1]) * (n - i) * i;
    cout << ans << '\n';
    return 0;
}