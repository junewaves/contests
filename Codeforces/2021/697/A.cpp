#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int64_t x;
        cin >> x;
        cout << (x & (x - 1) ? "YES\n" : "NO\n");
    }
    return 0;
}
