#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int& v : a)
        cin >> v;
    for (int& v : b)
        cin >> v;
    if ((n & 1) && a[n / 2] != b[n / 2]) {
        cout << "No\n";
        return;
    }
    multiset<pair<int, int>> sa, sb;
    for (int i = 0; i < n / 2; i++) {
        int u = a[i], v = a[n - i - 1];
        if (u < v)
            swap(u, v);
        sa.emplace(u, v);
    }
    for (int i = 0; i < n / 2; i++) {
        int u = b[i], v = b[n - i - 1];
        if (u < v)
            swap(u, v);
        sb.emplace(u, v);
    }
    if (sa == sb)
        cout << "Yes\n";
    else
        cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _n;
    cin >> _n;
    while (_n--) {
        solve();
    }
    return 0;
}
