#include <bits/stdc++.h>
using namespace std;
#ifndef _VSCODE_DEBUG
#define endl '\n'
#endif
typedef long long int ll;

char c[102];
void solve() {
    memset(c, 0, sizeof(c));
    cin >> c;
    int buffer = 0, size = strlen(c);
    for (int i = 0; i < size; i++) {
        int t = c[i] - '0', n = (i + 1 == size ? 0 : c[i + 1] - '0');
        for (int j = 0; j < t - buffer; j++) {
            cout << '(';
        }
        cout << c[i];
        for (int j = 0; j < t - n; j++) {
            cout << ')';
        }
        buffer = t;
    }
    cout << endl;
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
