#include <bits/stdc++.h>
using namespace std;

struct splitmix64_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = 
            chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k;
        cin >> n >> k;
        unordered_set<int, splitmix64_hash> cnt;
        for (int i = 0; i < n; i++) {
            int it;
            cin >> it;
            if (it % k != 0)
                cnt.insert(it % k);
        }
        if (cnt.empty() || (k & (k - 1)) == 0) {
            cout << "YES\n";
            continue;
        }
        vector<int> helper, other;
        for (auto p : cnt) {
            int m = k / p;
            if (k % p != 0 || (m & (m - 1)) != 0)
                other.push_back(p);
            else 
                helper.push_back(p);
        }
        if (helper.empty()) {
            cout << "NO\n";
            continue;
        }
        int h = *min_element(helper.begin(), helper.end());
        bool ok = true;
        for (int x : other) {
            if ((k - x) % h != 0) {
                ok = false;
                break;
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}
