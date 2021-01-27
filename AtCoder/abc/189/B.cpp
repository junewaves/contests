#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, x;
    cin >> n >> x;
    x *= 100;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int v, p;
        cin >> v >> p;
        sum += v * p;
        if (sum > x) {
            cout << i + 1 << '\n';
            return 0;
        }
    }
    cout << -1 << '\n';
    return 0;
}
