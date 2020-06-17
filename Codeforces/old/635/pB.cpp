// Codeforces Round #635 (Div. 2) (4/15)
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int ll;
void solve() {
    int x, n, m;
    cin >> x >> n >> m;
    if (x <= 20) {
        if (m * 10 >= x)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        return;
    }
    n = min(n, 17);
    while (n > 0) {
        x = x / 2 + 10;
        n--;
    }
    if (m * 10 >= x)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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