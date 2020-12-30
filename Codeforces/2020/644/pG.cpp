#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    if (n * a == m * b) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
        return;
    }
    vector<int> tmp(m, 0);
    for (int i = 0; i < a; i++) {
        tmp[i] = 1;
    }
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << tmp[k];
            k = (k + 1) % m;
        }
        cout << '\n';
        k = (k + a) % m;
    }
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