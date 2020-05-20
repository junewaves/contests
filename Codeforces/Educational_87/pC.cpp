#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const double PI = acos(-1.0);
void solve() {
    int n;
    double ans;
    cin >> n;
    if (n % 2) {
        ans = cos(PI / (4.0 * n)) / sin(PI / (2.0 * n));
    } else {
        ans = 1.0 / tan(PI / (2.0 * n));
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _n;
    cin >> _n;
    cout << fixed << setprecision(9);
    while (_n--) {
        solve();
    }
    return 0;
}
