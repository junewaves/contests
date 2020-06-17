#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    ll a1 = 1919434;  // * 10000000
    ll a2 = 2495775;
    const int cut = 10000000;
    while (n--) {
        ll b;
        cin >> b;
        bool plus = 0;
        ll c = a1 * b, d = a2 * b;
        if (d > cut) {
            if (d % cut > 0)
                plus = 1;
        }
        c += d / cut;
        if (c % 200000 > 0)
            plus = 1;
        c /= 200000;
        cout << c + plus << '\n';
    }
    return 0;
}
