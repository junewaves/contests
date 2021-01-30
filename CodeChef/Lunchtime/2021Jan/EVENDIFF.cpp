#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        int odd = 0;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            odd += a % 2;
        }
        cout << min(odd, n - odd) << '\n';
    }
    return 0;
}
