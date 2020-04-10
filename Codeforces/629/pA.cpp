#include <bits/stdc++.h>
using namespace std;
#ifndef _VSCODE_DEBUG
#define endl '\n'
#endif
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, a, b;
    for (cin >> n; n; n--) {
        cin >> a >> b;
        int c = (a % b);
        if (c > 0)
            cout << b - c << endl;
        else {
            cout << 0 << endl;
        }
    }

    return 0;
}