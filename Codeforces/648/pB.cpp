#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    vector<bool> test = { 0, 0 };

    for (int& va : a)
        cin >> va;
    for (int& vb : b) {
        cin >> vb;
        test[vb] = 1;
    }
    if (test[0] && test[1]) {
        cout << "Yes\n";
        return;
    }
    int p = a[0];
    bool ok = true;
    for (int i = 0; i < n; i++) {
        if (a[i] < p) {
            ok = false;
            break;
        }
    }
    if (ok)
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
