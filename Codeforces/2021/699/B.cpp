#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int &it : a) cin >> it;
        while (k > 0) {
            bool ok = false;
            for (int i = 0; i < n - 1; i++) {
                if (a[i] < a[i + 1]) {
                    a[i]++;
                    k--;
                    ok = true;
                    if (k == 0)
                        cout << i + 1 << '\n';
                    break;
                }
            }
            if (!ok) {
                cout << "-1\n";
                break;
            }
        }
    }
    return 0;
}
