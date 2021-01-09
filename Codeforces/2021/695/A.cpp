#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        if (n == 1) {
            cout << "9\n";
            continue;
        } else if (n == 2) {
            cout << "98\n";
            continue;
        }
        cout << "98";
        for (int i = 2, x = 9; i < n; i++) {
            cout << x;
            x = (x + 1) % 10;
        }
        cout << '\n';
    }
    return 0;
}