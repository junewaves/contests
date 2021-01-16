#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[x]++;
    }
    int need = k;
    int64_t ans = 0;
    for (int i = 0; i <= n; i++) {
        if (a[i] < need) {
            ans += i * int64_t(need - a[i]);
            if (a[i] == 0) break;
            need = a[i];
        }
    }
    cout << ans << '\n';
    return 0;
}
