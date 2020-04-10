#include <bits/stdc++.h>
using namespace std;
#ifndef _VSCODE_DEBUG
#define endl '\n'
#endif
constexpr int maxn = 50001;
int _, n;
char x[maxn], a[maxn], b[maxn];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    for (cin >> _; _; _--) {
        cin >> n >> x;
        bool splited = false;
        for (int i = 0; i < n; i++) {
            if (!splited) {
                if (x[i] == '2') {
                    a[i] = b[i] = '1';
                } else if (x[i] == '0') {
                    a[i] = b[i] = '0';
                } else {
                    splited = true;
                    a[i] = '1';
                    b[i] = '0';
                }
            } else {
                if (x[i] == '2') {
                    a[i] = '0';
                    b[i] = '2';
                } else if (x[i] == '0') {
                    a[i] = b[i] = '0';
                } else {
                    a[i] = '0';
                    b[i] = '1';
                }
            }
        }
        for (int i = 0; i < n; i++) {
            cout << a[i];
        }
        cout << endl;
        for (int i = 0; i < n; i++) {
            cout << b[i];
        }
        cout << endl;
    }
    return 0;
}