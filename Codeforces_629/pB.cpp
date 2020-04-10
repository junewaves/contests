#include <bits/stdc++.h>
using namespace std;
#ifndef _VSCODE_DEBUG
#define endl '\n'
#endif
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, n, k;
    for (cin >> a; a; a--) {
        cin >> n >> k;
        int i = 1, s = 0;
        while (s + i < k) {
            s += i++;
        }
        for (int j = 0; j < n; j++) {
            int w = n - j;
            if (w == i + 1 || w == k - s)
                cout << 'b';
            else
                cout << 'a';
        }
        cout << '\n';
    }
    return 0;
}