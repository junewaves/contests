#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifdef _LOCAL_DEBUG
#include "templates/debug.h"
#else
#define debug(...) 
#endif

void print(int x, int y) {
    cout << x << ' ' << y << '\n';
}

void solve() {
    int n, m, x ,y;
    cin >> n >> m >> x >> y;
    int sx = x, sy = y;
    print(x, y);
    print(1, y);
    for (int i = 1; i < y; i++)
        print(1, i);
    for (int i = y + 1; i <= m; i++)
        print(1, i);
    bool right = true;
    for (int i = 2; i <= n; i++) {
        if (right) {
            for (int j = m; j >= 1; j--) {
                if (i != sx || j != sy)
                    print(i, j);
            }
        } else {
            for (int j = 1; j <= m; j++) {
                if (i != sx || j != sy)
                    print(i, j);
            }
        }
        right = !right;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt = 1;
    // cin >> tt;
    while (tt--)
        solve();
    return 0;
}