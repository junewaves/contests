// Kickstart 2020 Round B (4/19)
#include <bits/stdc++.h>
using namespace std;
#ifndef _VSCODE_DEBUG
#define endl '\n'
#endif
typedef long long int ll;
void solve() {
    int n, a, b, c, peak = 0;
    cin >> n >> a >> b;
    for (int i = 2; i < n; i++) {
        cin >> c;
        if (b > a && b > c)
            peak++;
        a = b;
        b = c;
    }
    cout << peak << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _n;
    cin >> _n;
    for (int i = 1; i <= _n; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
}