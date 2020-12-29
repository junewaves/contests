#include <bits/stdc++.h>
using namespace std;

struct BIT {
    vector<int> t;
    BIT(int n) : t(n) {}
    void add(int i, int x) {
        for (; i < int(t.size()); i |= i + 1)
            t[i] += x;
    }
    int sum(int l, int r) {
        int res = 0;
        for (; r > 0; r &= r - 1)
            res += t[r - 1];
        for (; l > 0; l &= l - 1)
            res -= t[l - 1];
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> y(n);
    vector<array<int, 2>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1];
        y[i] = a[i][1];
    }
    sort(a.begin(), a.end());
    sort(y.begin(), y.end());
    for (int i = 0; i < n; i++) {
        a[i][0] = i;
        a[i][1] = lower_bound(y.begin(), y.end(), a[i][1]) - y.begin();
    }
    int64_t ans = n + 1;
    for (int i = 0; i < n; i++) {
        BIT bit(n);
        int upper = 1, lower = 1;
        for (int j = i + 1; j < n; j++) {
            if (a[j][1] > a[i][1]) {
                ans += (bit.sum(a[j][1], n) + 1) * lower;
                upper++;
            } else {
                ans += (bit.sum(0, a[j][1]) + 1) * upper;
                lower++;
            }
            bit.add(a[j][1], 1);
        }
    }
    cout << ans << '\n';
    return 0;
}