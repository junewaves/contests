#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    for (int &it : a)
        cin >> it;
    for (int &it : b)
        cin >> it;
    for (int &it : c)
        cin >> it;
    vector<int> ans(n);
    ans[0] = a[0];
    for (int i = 1; i < n - 1; i++) {
        if (a[i] == ans[i - 1])
            ans[i] = b[i];
        else
            ans[i] = a[i];
    }
    if (a[n - 1] != ans[0] && a[n - 1] != ans[n - 2])
        ans[n - 1] = a[n - 1];
    else if (b[n - 1] != ans[0] && b[n - 1] != ans[n - 2])
        ans[n - 1] = b[n - 1];
    else if (c[n - 1] != ans[0] && c[n - 1] != ans[n - 2])
        ans[n - 1] = c[n - 1];
    for (int i = 0; i < n; i++)
        cout << ans[i] << " \n"[i == n - 1];
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}