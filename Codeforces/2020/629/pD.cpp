#include <bits/stdc++.h>
using namespace std;
#ifndef _VSCODE_DEBUG
#define endl '\n'
#endif
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q, n;
    for (cin >> q; q; q--) {
        cin >> n;
        vector<int> f(n);
        vector<int> color(n);
        vector<int> color2(n);
        int cs = 1, alter = 0;
        cin >> f[0];
        color[0] = 1;
        color2[0] = 1;
        for (int i = 1; i < n; i++) {
            cin >> f[i];
            if (f[i] == f[i - 1]) {
                color[i] = color[i - 1];
                if (!alter) {
                    color2[i] = (color2[i - 1] == 1) ? 2 : 1;
                    alter = 1;
                } else {
                    color2[i] = color2[i - 1];
                }
            } else {
                color[i] = (color[i - 1] == 1) ? 2 : 1;
                color2[i] = (color2[i - 1] == 1) ? 2 : 1;
                cs = 2;
            }
        }
        alter = 0;
        if (f[n - 1] != f[0] && color[n - 1] == color[0]) {
            if (color2[n - 1] != color[0]) {
                alter = 1;
            } else if (f[n - 2] == f[n - 1]) {
                color[n - 1] = (color[0] == 1) ? 2 : 1;
            } else if (color[n - 2] == color[0]) {
                color[n - 1] = (color[0] == 1) ? 2 : 1;
            } else if (color2[n - 2] == color2[0]) {
                color2[n - 1] = (color2[0] == 1) ? 2 : 1;
                alter = 1;
            } else {
                color[n - 1] = 3;
                cs = 3;
            }
        }
        cout << cs << endl;
        if (alter) {
            for (int i = 0; i < n; i++) {
                cout << color2[i] << " \n"[i == n - 1];
            }
        } else {
            for (int i = 0; i < n; i++) {
                cout << color[i] << " \n"[i == n - 1];
            }
        }
    }
    return 0;
}