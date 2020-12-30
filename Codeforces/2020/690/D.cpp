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
        int sum = 0;
        for (int &it : a) {
            cin >> it;
            sum += it;
        }
        for (int x = n; x > 0; x--) {
            if (sum % x != 0) continue;
            int target = sum / x;
            int cur = 0;
            for (int i = 0; i < n; i++) {
                cur += a[i];
                if (cur == target)
                    cur = 0;
                else if (cur > target)
                    break;
            }
            if (cur == 0) {
                cout << n - x << '\n';
                break;
            }
        }
    }
    return 0;
}