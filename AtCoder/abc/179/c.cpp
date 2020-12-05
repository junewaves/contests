#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> pr(n + 1);
    for (int i = 2; i <= n; i++) {
        if (pr[i] == 0) {
            for (int j = i; j <= n; j += i)
                pr[j] = i;
        }
    }
    int ans = 1;
    for (int i = 2; i < n; i++) {
        map<int, int> cnt;
        int x = i;
        while (x > 1) {
            cnt[pr[x]]++;
            x /= pr[x];
        }
        int y = 1;
        for (auto p : cnt) {
            y *= p.second + 1;
        }
        ans += y;
    }
    cout << ans << '\n';
    return 0;
}