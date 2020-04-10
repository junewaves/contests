#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int ll;
void solve() {
    int n, p, c;
    vector<pair<int, int>> data;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p >> c;
        data.emplace_back(p, c);
    }
    p = c = 0;
    bool ok = true;
    for (const auto& pp : data) {
        int a = pp.first, b = pp.second;
        if (a < p || b < c || b - c > a - p) {
            ok = false;
            break;
        }
        p = a, c = b;
    }
    if (ok)
        cout << "YES\n";
    else
        cout << "NO\n";
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