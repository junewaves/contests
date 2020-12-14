#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int64_t k, l, r, t, x, y;
    cin >> k >> l >> r >> t >> x >> y;
    bool good = [&]{
        if (x >= y) {
            if (k + y <= r) k += y;
            k -= x;
            if (t == 1)
                return k >= l;
            else
                return (k - l) / (t - 1) >= x - y;
        } else {
            vector<bool> vis(x);
            while (!vis[k % x]) {
                vis[k % x] = true;
                int64_t z = (k - l) / x;
                if (z >= t) return true;
                t -= z;
                k += y - z * x;
                if (k > r) return false;
            }
            return true;
        }
    }();
    cout << (good ? "Yes\n" : "No\n");
    return 0;
}