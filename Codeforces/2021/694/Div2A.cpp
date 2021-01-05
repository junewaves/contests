#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, x;
        cin >> n >> x;
        int64_t max_beauty = 0, sum = 0;
        for (int i = 0, y; i < n; i++) {
            cin >> y;
            max_beauty += (y + x - 1) / x;
            sum += y;
        }
        cout << (sum + x - 1) / x << ' ' << max_beauty << '\n';
    }
    return 0;
}