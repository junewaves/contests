#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    ll ans = 0;
    int it, one = 0;
    for (int i = 0; i < n; i++) {
        cin >> it;
        if (it >= 2) {
            if (one > 0) {
                int g = min(one, it / 2);
                ans += g;
                one -= g;
                it -= g * 2;
            }
            if (it >= 3) {
                ans += it / 3;
                it %= 3;
            }
            one += it;
        } else if (it == 1) {
            ++one;
        }
    }
    cout << ans << '\n';
    return 0;
}
