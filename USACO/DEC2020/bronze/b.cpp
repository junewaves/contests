#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> b(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = b[i-1] + a[i];
    }
    int ans = 0;
    for (int len = 1; len <= n; len++) {
        for (int i = 0; i + len <= n; i++) {
            int sum = b[i + len] - b[i];
            if (sum % len != 0) continue;
            int avg = sum / len;
            bool ok = false;
            for (int j = i + 1; j <= i + len; j++)
                ok |= a[j] == avg;
            if (ok) ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}