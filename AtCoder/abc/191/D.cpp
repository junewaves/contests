#include <bits/stdc++.h>
using namespace std;

constexpr int64_t mul = 10000;
constexpr int64_t offset_s = 2e9;
constexpr int64_t offset = offset_s * mul;

int64_t read() {
    static const int off[5] = {-1, 1000, 100, 10, 1};
    string s;
    cin >> s;
    size_t dot = s.find('.');
    int64_t ret = stoi(s.substr(0, dot)) * mul;
    if (dot != string::npos) {
        string f = s.substr(dot + 1);
        ret += stoi(f) * off[f.size()];
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int64_t x = read();
    int64_t y = read();
    int64_t r = read();

    int64_t ans = 0;
    int64_t start = (y - r + offset) / mul - offset_s;
    int64_t end = (y + r - 1 + offset) / mul + 1 - offset_s;
    for (int64_t i = start; i <= end; i++) {
        int64_t h = y - i * mul;

        int64_t low = -offset_s, high = x;
        while (low <= high) {
            int64_t mid = (low + high) / 2;
            if ((mid - x) * (mid - x) + h * h <= r * r) 
                high = mid - 1;
            else
                low = mid + 1;
        }
        int64_t L = (low - 1 + offset) / mul + 1 - offset_s;
        
        low = x, high = offset_s;
        while (low <= high) {
            int64_t mid = (low + high) / 2;
            if ((mid - x) * (mid - x) + h * h <= r * r) 
                low = mid + 1;
            else
                high = mid - 1;
        }
        int64_t R = (high + offset) / mul - offset_s;

        if (R >= L)
            ans += R - L + 1;
    }
    cout << ans << '\n';
    return 0;
}
