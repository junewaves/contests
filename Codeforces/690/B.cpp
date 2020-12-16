#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        bool ok = false;
        for (int left = 0; left <= 4; left++) {
            int right = 4 - left;
            if (s.substr(0, left) + s.substr(n - right, right) == "2020") {
                ok = true;
                break;
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}