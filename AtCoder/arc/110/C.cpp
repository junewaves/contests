#include <bits/stdc++.h>
using namespace std;

struct BIT {
    vector<int> t;
    BIT(int n) : t(n) {}
    void update(int i, int x) {
        for (; i < (int)t.size(); i |= i + 1) 
            t[i] += x; 
    }
    int query(int i) {
        int res = 0;
        for (; i > 0; i &= i - 1)
            res += t[i - 1];
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    BIT bit(n + 1);
    int64_t inversion = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        inversion += bit.query(n + 1) - bit.query(a[i]);
        bit.update(a[i], 1);
    }
    if (inversion != n - 1) {
        cout << "-1\n";
        return 0;
    }
    int last = n;
    for (int i = n - 2; i >= 0; i--) {
        if (a[i] > a[i + 1]) {
            for (int j = i + 1; j < last; j++) {
                swap(a[j - 1], a[j]);
                cout << j << '\n';
            }
            last = i + 1;
        }
    }
    for (int j = 1; j < last; j++) {
        cout << j << '\n';
    }
    return 0;
}