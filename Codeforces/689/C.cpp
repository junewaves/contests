#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for (int &it : a) cin >> it;
        int suf = 0;
        for (int i = n - 1; i >= 0 && a[i] == i + 1; i--) suf++;
        double pr = suf == n ? 1.0 : 0.0;
        for (int i = 0; i < m; i++) {
            int r;
            double p;
            cin >> r >> p;
            if (r + suf >= n)
                pr += (1 - pr) * p;
        }
        cout << fixed << setprecision(10) << pr << '\n';
    }
    return 0;
}