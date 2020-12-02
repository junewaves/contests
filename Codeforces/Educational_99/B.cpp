#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int x;
        cin >> x;
        int n = 0, y = 1;
        while (n < x) {
            n += y;
            y++;
        }
        if (n == x || n - x > 1)
            cout << y - 1 << '\n';
        else
            cout << y << '\n';
    }
    return 0;
}