#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, m, mxa = 0, mxb = 0;
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            a[i] += a[i - 1];
            mxa = max(mxa, a[i]);
        }
        cin >> m;
        vector<int> b(m + 1);
        for (int i = 1; i <= m; i++) {
            cin >> b[i];
            b[i] += b[i - 1];
            mxb = max(mxb, b[i]);
        }
        cout << mxa + mxb << '\n';
    }
    return 0;
}