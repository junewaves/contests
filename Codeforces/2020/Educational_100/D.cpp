#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        // https://codeforces.com/contest/1463/submission/101531312
        int n;
        cin >> n;
        vector<int> b(n), missing;
        missing.reserve(n);
        int prv = 1;
        for (int &it : b) {
            cin >> it;
            for (int x = prv; prv < it; prv++)
                missing.push_back(x);
            prv = it + 1;
        }
        for (int x = prv; prv <= 2 * n; prv++)
            missing.push_back(x);
        int low = 0, high = n;
        while (low < high) {
            int mid = (low + high + 1) / 2;
            bool ok = true;
            for (int i = 0; ok && i < mid; i++)
                ok &= b[i] < missing[n - mid + i];
            if (ok)
                low = mid;
            else
                high = mid - 1;
        }
        int save = low;
        low = 0, high = n;
        while (low < high) {
            int mid = (low + high) / 2;
            bool ok = true;
            for (int i = mid; ok && i < n; i++)
                ok &= b[i] > missing[i - mid];
            if (ok)
                high = mid;
            else
                low = mid + 1;
        }
        cout << max(save - low + 1, 0) << '\n';
    }
    return 0;
}