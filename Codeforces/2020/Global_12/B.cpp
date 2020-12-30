#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k;
        cin >> n >> k;
        vector<int> x(n), y(n);
        bool ok = false;
        for (int i = 0; i < n; i++)
            cin >> x[i] >> y[i];
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (abs(x[i] - x[j]) + abs(y[i] - y[j]) <= k) {
                    cnt++;
                }
            }
            if (cnt == n) {
                ok = true;
                break;
            }
        }
        cout << (ok ? 1 : -1) << '\n';
    }
    return 0;
}