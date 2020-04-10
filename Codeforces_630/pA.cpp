#include <bits/stdc++.h>
using namespace std;
#ifndef _VSCODE_DEBUG
#define endl '\n'
#endif
typedef long long int ll;
void solve() {
    int a, b, c, d;
    int x[3], y[3];
    cin >> a >> b >> c >> d;
    for (int i = 0; i < 3; i++) {
        cin >> x[i] >> y[i];
    }
    int up = d - c, right = b - a;
    int l = x[1] - x[0], r = x[2] - x[0];
    int D = y[1] - y[0], u = y[2] - y[0];

    // if ((l == 0 && r == 0) && (c != 0 || d != 0))
    //     cout << "No" << endl;
    // if ((D == 0 && u == 0) && (a != 0 || b != 0))
    //     cout << "No" << endl;
    if (((D == 0 && u == 0) && (c != 0 || d != 0)) ||
        ((l == 0 && r == 0) && (a != 0 || b != 0)) ||
        (right < l || right > r || up < D || up > u))
        cout << "No" << endl;
    else
        cout << "Yes" << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _n;
    cin >> _n;
    while (_n--) {
        solve();
    }
}