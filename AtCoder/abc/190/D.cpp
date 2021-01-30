#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int64_t n;
    cin >> n;
    n *= 2;
    vector<pair<int64_t, int64_t>> f;
    for (int64_t i = 1; i * i <= n; i++)
        if (n % i == 0)
            f.emplace_back(i, n / i);
    int64_t ans = 0;
    for (auto [x, y] : f) {
        if ((x + 1 - y) % 2 == 0) 
            ans++;
        if (x != y && (y + 1 - x) % 2 == 0)
            ans++;
    }
    cout << ans << '\n';
    return 0;
}
