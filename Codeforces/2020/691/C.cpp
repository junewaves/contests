#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int64_t> a(n), b(m);
    for (auto &it : a) cin >> it;
    for (auto &it : b) cin >> it;
    if (n == 1) {
        for (int i = 0; i < m; i++)
            cout << b[i] + a[0] << " \n"[i == m - 1];
        return 0;
    }
    sort(a.begin(), a.end());
    int64_t g = a[0] - a[1];
    for (int i = 2; i < n; i++)
        g = gcd(a[i] - a[i-1], g);
    for (int i = 0; i < m; i++)
        cout << gcd(a[0] + b[i], g) << " \n"[i == m - 1];
    return 0;
}