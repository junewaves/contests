#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    ll n;
    cin >> n;
    ll lo = 0, hi = 400;
    while (lo < hi) {
        ll mid = (lo + hi) / 2;
        ll x = mid % 10, y = mid / 10;
        ll ans = 1;
        for (int i = 0; i < 10; i++) {
            if (i < x)
                ans *= y + 1;
            else
                ans *= y;
        }
        if (ans >= n)
            hi = mid;
        else
            lo = mid + 1;
    }
    // cout << lo << '\n';
    string str = "codeforces";
    ll x = lo % 10, y = lo / 10;
    for (int i = 0; i < 10; i++) {
        int cnt = (i < x) ? y + 1 : y;
        for (int j = 0; j < cnt; j++) {
            cout << str[i];
        }
    }
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
