#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll a, b, c, k;
    cin >> a >> b >> c >> k;
    if (k <= a)
        cout << k << endl;
    else if (a + b >= k) {
        cout << a << endl;
    } else {
        k -= (a + b);
        cout << a - k << endl;
    }
}
