#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll a, b, c;
    cin >> a >> b >> c;
    ll g = gcd(a, b);
    if (c % g) {
        cout << "N\n";
    } else {
        a /= g, b /= g, c /= g;
        ll x = 0;
        for (;; x++) {
            if (c % b == 0) {
                cout << "Y\n";
                cout << x << " " << c / b << "\n";
                break;
            }
            c -= a;
        }
    }
    return 0;
}
