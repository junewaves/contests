#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    ll n;
    cin >> n;
    int lo = 0, hi = 400;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        int x = mid % 10, y = mid / 10;
        ll res = 1;
        for (int i = 0; i < 10; i++) {
            res *= y + (i < x ? 1 : 0);
        }
        if (res >= n)
            hi = mid;
        else
            lo = mid + 1;
    }
    string str = "codeforces";
    int x = lo % 10, y = lo / 10;
    for (int i = 0; i < 10; i++) {
        int cnt = y + (i < x ? 1 : 0);
        while (cnt--) {
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
