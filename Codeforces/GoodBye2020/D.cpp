#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        int64_t sum = 0;
        vector<array<int, 2>> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i][0];
            sum += a[i][0];
        }
        for (int i = 1, u, v; i < n; i++) {
            cin >> u >> v;
            --u, --v;
            a[u][1]++;
            a[v][1]++;
        }
        sort(a.begin(), a.end(), greater<>());
        cout << sum;
        for (auto [w, d] : a)
            for (int i = 0; i < d - 1; i++)
                cout << ' ' << (sum += w);
        cout << '\n';
    }
    return 0;
}