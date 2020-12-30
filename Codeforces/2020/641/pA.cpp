#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
void solve() {
    int n, k;
    cin >> n >> k;
    ll ans;
    if (n % 2 == 0)
        ans = (ll)n + 2LL * k;
    else {
        int j;
        for (j = 3; j * j <= n; j += 2) {
            if (n % j == 0)
                break;
        }
        if (n % j == 0)
            ans = n + j + 2LL * (k - 1);
        else
            ans = 2LL * (n + k - 1);
    }
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _n;
    cin >> _n;
    while (_n--) {
        solve();
    }
    return 0;
}
