#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int good = 0, odd = 0, even = 0;
    bool par = false;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if ((bool)(a[i] & 1) == par) {
            ++good;
        } else {
            if (a[i] & 1)
                odd++;
            else
                even++;
        }
        par = !par;
    }
    if (odd != even)
        cout << "-1\n";
    else
        cout << odd << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _n;
    cin >> _n;
    while (_n--) {
        solve();
    }
    return 0;
}
