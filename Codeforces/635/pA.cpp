// Codeforces Round #635 (Div. 2) (4/15)
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int ll;
void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (d < c + b)
        cout << b << " " << c << " " << d << endl;
    else
        cout << b << " " << c << " " << b + c - 1 << endl;
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