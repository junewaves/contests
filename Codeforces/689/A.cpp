#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k;
        cin >> n >> k;
        char c[4] = {'a', 'b', 'c'};
        for (int i = 0; i < n; i++) {
            cout << c[i % 3];
        }
        cout << '\n';
    }
    return 0;
}