#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    ll ans = 0;
    for (int& it : a)
        cin >> it;
    bool first = true;
    int one = 0;
    for (int& it : a) {
        // if (it) {
        if (it >= 2) {
            if (one) {
                int g = min(one, it / 2);
                ans += g;
                one -= g;
                it -= g * 2;
                if (it >= 3) {
                    ans += it / 3;
                    it %= 3;
                }
                if (it)
                    one += it;
            } else {
                if (it >= 3) {
                    ans += it / 3;
                    it %= 3;
                }
                one += it;
            }
        } else if (it == 1) {
            one++;
        }
        // }
    }
    cout << ans << '\n';
    // for (int i = n - 1; i )
    return 0;
}
