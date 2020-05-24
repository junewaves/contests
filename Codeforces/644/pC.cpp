#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int co = 0, ce = 0;
    for (int i : a) {
        if (i % 2) {
            co++;
        } else {
            ce++;
        }
    }
    if (co % 2 == 0 && ce % 2 == 0) {
        cout << "Yes\n";
        return;
    }
    sort(a.begin(), a.end());
    for (int i = 1; i < n; i++) {
        if (a[i] - a[i - 1] == 1) {
            cout << "Yes\n";
            return;
        }
    }
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
