#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll a, b, c;
    cin >> a >> b >> c;
    ll g = gcd(a, b);
    if (c % g) {
        cout << "N" << endl;
    } else {
        a = a / g, b = b / g, c = c / g;
        ll x = 0, t = c;
        for (;; x++) {
            if (t % b == 0) {
                cout << "Y" << endl;
                cout << x << " " << t / b << endl;
                break;
            }
            t -= a;
        }
    }
    return 0;
}
