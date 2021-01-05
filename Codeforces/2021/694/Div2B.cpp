#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, x;
        cin >> n >> x;
        vector<int> a(n), p(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            for (int y = a[i]; y % x == 0; y /= x)
                p[i]++;
        }
        int rounds = *min_element(p.begin(), p.end()) + 1;
        bool alive = true;
        int64_t ans = 0;
        for (int i = 0; i < n; i++) {
            if (alive && p[i] < rounds)
                alive = false;
            int64_t mul = rounds + int(alive);
            ans += mul * a[i];
        }
        cout << ans << '\n';
    }
    return 0;
}