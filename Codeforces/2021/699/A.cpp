#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int x, y;
        string s;
        cin >> x >> y >> s;
        int max_x = 0, max_y = 0, min_x = 0, min_y = 0;
        for (char c : s) {
            if (c == 'U') {
                max_y++;
            } else if (c == 'D') {
                min_y--;
            } else if (c == 'R') {
                max_x++;
            } else if (c == 'L') {
                min_x--;
            }
        }
        if (min_x <= x && x <= max_x && min_y <= y && y <= max_y)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
