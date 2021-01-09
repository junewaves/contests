#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        auto check = [&](int i) -> int {
            if (i <= 0 || i >= n - 1)
                return 0;
            else
                return int((a[i - 1] < a[i] && a[i] > a[i + 1]) || 
                           (a[i - 1] > a[i] && a[i] < a[i + 1]));
        };
        auto local = [&](int i) -> int {
            int res = 0;
            for (int j : {-1, 0, 1})
                res += check(i + j);
            return res;
        };
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += check(i);
        int ans = sum;
        for (int i = 0; i < n; i++) {
            int x = local(i);
            int y = x;
            int tmp = a[i];
            for (int j : {-1, 1}) {
                if (i + j >= 0 && i + j < n) {
                    a[i] = a[i + j];
                    y = min(y, local(i));
                }
            }
            ans = min(ans, sum - x + y);
            a[i] = tmp;
        }
        cout << ans << '\n';
    }
    return 0;
}