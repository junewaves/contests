#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<pair<int, int>> ans;
        ans.reserve(n + 5);
        while (n > 2) {
            int s = ceil(sqrt(n));
            for (int i = n - 1; i > s; i--)
                ans.emplace_back(i, n);
            ans.emplace_back(n, s);
            ans.emplace_back(n, s);
            n = s;
        }
        cout << ans.size() << '\n';
        for (auto [a, b] : ans)
            cout << a << ' ' << b << '\n';
    }
    return 0;
}