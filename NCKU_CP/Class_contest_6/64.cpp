#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll a1 = 1919434LL;  // * 10000000
const ll a2 = 2495775LL;  // 1.1 ^ 31
const int m1 = 1e7;
const int m2 = 2e5;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    while (n--) {
        ll b, c, d;
        cin >> b;
        d = a2 * b;
        c = a1 * b + d / m1;
        int r = (d % m1 || c % m2) ? 1 : 0;
        cout << c / m2 + r << '\n';
    }
    return 0;
}
