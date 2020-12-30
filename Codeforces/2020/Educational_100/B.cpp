#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n);
        int64_t s[2]{};
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            s[i % 2] += a[i] - 1;
        }
        for (int i = 0; i < n; i++)
            cout << (i % 2 == int(s[1] < s[0]) ? 1 : a[i]) << ' ';
        cout << '\n';
    }
    return 0;
}