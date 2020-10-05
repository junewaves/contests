#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<array<int, 2>> a(n), b(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1];
    }
    for (int j = 0; j < m; j++) {
        cin >> b[j][0] >> b[j][1];
    }
    const int mxy = 1e6 + 5;
    vector<int> min_y(mxy, -1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int up = max(0, b[j][1] - a[i][1] + 1);
            int right = max(0, b[j][0] - a[i][0] + 1);
            if (right > 0 && up > 0) {
                min_y[right - 1] = max(min_y[right - 1], up);
            }
        }
    }
    for (int i = mxy - 1; i >= 0; ) {
        if (min_y[i] != -1) {
            int j = i - 1;
            for (; j >= 0 && min_y[j] < min_y[i]; j--) {
                min_y[j] = min_y[i];
            }
            i = j;
        } else {
            i--;
        }
    }
    int ans = mxy;
    for (int i = 0; i < mxy; i++) {
        if (min_y[i] == -1) {
            ans = min(ans, i);
            break;
        }
        ans = min(ans, i + min_y[i]);
    }
    cout << ans << '\n';
    return 0;
}