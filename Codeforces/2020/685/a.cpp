#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        if (n <= 3) {
            cout << n - 1 << '\n';
        } else {
            cout << (n % 2 ? 3 : 2) << '\n';
        }
    }
    return 0;
}