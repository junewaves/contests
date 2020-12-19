#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        bool ok = true;
        for (int x = i; ok && x; x /= 10) {
            ok &= (x % 10) != 7;
        }
        for (int x = i; ok && x; x /= 8) {
            ok &= (x % 8) != 7;
        }
        ans += ok;
    }
    cout << ans << '\n';
    return 0;
}