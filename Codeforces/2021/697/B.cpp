#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        bool ret = [] () -> bool {
            int n, x = 0;
            cin >> n;
            while (x <= n) {
                if ((n - x) % 2021 == 0)
                    return true;
                x += 2020;
            }
            return false;
        }();
        cout << (ret ? "YES\n" : "NO\n");
    }
    return 0;
}

