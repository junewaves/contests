#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 1;
int t[N * 2];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    for (int i = a; i <= b; i++) {
        t[i + b]++;
        t[i + c + 1]--;
    }
    ll ans = 0, s = 0;
    for (int i = a + b; i <= b + c; i++) {
        s += t[i];
        if (i > d)
            ans += (ll)(d - c + 1) * s;
        else if (i > c)
            ans += (ll)(i - c) * s;
    }
    cout << ans << '\n';
    return 0;
}
