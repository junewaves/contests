#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, m, t;
    cin >> n >> m >> t;
    int x = n, y = 0;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        x -= a - y;
        if (x <= 0) {
            cout << "No\n";
            return 0;
        }
        x = min(n, x + b - a);
        y = b;
    }
    x -= t - y;
    cout << (x <= 0 ? "No\n" : "Yes\n");
}
