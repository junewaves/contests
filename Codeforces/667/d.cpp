#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int64_t n, s;
        cin >> n >> s;
        int64_t moves = 0;
        int64_t base = 1;
        while (1) {
            int sum = 0;
            int64_t x = n;
            while (x) {
                sum += x % 10;
                x /= 10;
            }
            if (sum <= s) break;
            int d = n % 10;
            if (d > 0) {
                moves += (10 - d) * base;
                n += 10 - d;
            }
            n /= 10;
            base *= 10;
        }
        cout << moves << '\n';
    }
    return 0;
}