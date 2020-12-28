#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    constexpr int logn = 23;
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        for (char &c : s) c ^= 1;
        vector<bool> seen(n + 1);
        vector<int> pos;
        for (int i = 0; i < n; i++)
            if (s[i] == '1')
                pos.push_back(i);
        int m = pos.size();
        int cur = 0, mask = (1 << min(k, logn)) - 1;
        for (int i = 0, j = 0; i < n; i++) {
            cur = ((cur << 1) | (s[i] & 1)) & mask;
            if (int start = i - k + 1; start >= 0) {
                while (j < m && pos[j] < start) j++;
                if ((j == m || pos[j] >= i - logn) && cur <= n)
                    seen[cur] = true;
            }
        }
        int limit = min(n, mask), ans = 0;
        while (ans <= limit && seen[ans]) ans++;
        if (ans > limit) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        for (int i = k - 1; i >= 0; i--)
            cout << bool(i < logn && ((ans >> i) & 1));
        cout << '\n';
    }
    return 0;
}