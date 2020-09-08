#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> ans(n);
    sort(a.begin(), a.end());
    ans[0] = a.back();
    a.back() = -1;
    int g = ans[0];
    int i = 1;
    for (i = 1; i < n; i++) {
        int mxg = 0, idx = -1;
        for (int j = 0; j < n; j++) {
            if (a[j] == -1) continue;
            int gg = gcd(a[j], g);
            if (gg > mxg) {
                mxg = gg;
                idx = j;
            }
        }
        ans[i] = a[idx];
        a[idx] = -1;
        g = mxg;
        if (g == 1) break;
    }
    if (i < n) {
        for (int j = 0; j < n; j++) {
            if (a[j] != -1)
                ans[++i] = a[j];
        }
    }
    for (int it : ans)
        cout << it << ' ';
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}