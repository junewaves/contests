#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
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
        // cout << s << " ";
        if (i < c)
            continue;
        else if (i > d)
            ans += (d - c + 1) * s;
        else
            ans += (i - c) * s;
    }
    // cout << endl;
    cout << ans << endl;
    return 0;
}
