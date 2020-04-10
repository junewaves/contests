#include <bits/stdc++.h>
using namespace std;
#ifndef _VSCODE_DEBUG
#define endl '\n'
#endif
typedef long long int ll;
int a[105];
void solve() {
    int n, x, t;
    cin >> n >> x;
    memset(a, 0, sizeof(a));
    for (int i = 0; i < n; i++) {
        cin >> t;
        a[t]++;
    }
    int s = 0, i = 1;
    for (; i <= 100; i++) {
        if (a[i] > 0) {
            s++;
        } else if (x > 0) {
            s++, x--;
        } else {
            break;
        }
    }
    cout << s + x << endl;
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