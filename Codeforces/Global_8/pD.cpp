#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> b(20, 0);
    for (int i = 0, t; i < n; i++) {
        cin >> t;
        int x = 0;
        while (t) {
            b[x++] += (t & 1);
            t >>= 1;
        }
    }
    ll ans = 0;
    while (true) {
        ll r = 0;
        for (int i = 0; i < 20; i++) {
            if (b[i]) {
                r += 1 << i;
                --b[i];
            }
        }
        if (r == 0)
            break;
        ans += r * r;
    }
    cout << ans << '\n';
    return 0;
}
