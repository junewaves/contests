#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    long long x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cout << (x2 - x1) * (y2 - y1) + 1LL << '\n';
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
