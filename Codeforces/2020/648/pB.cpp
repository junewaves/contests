#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    int n, cnt = 0;
    cin >> n;
    vector<int> a(n), b(n);
    for (int& va : a)
        cin >> va;
    for (int& vb : b)
        cin >> vb, cnt += vb;
    if (0 < cnt && cnt < n) {
        cout << "Yes\n";
        return;
    }
    bool ok = true;
    for (int i = 1; i < n; i++) {
        if (a[i - 1] > a[i]) {
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
