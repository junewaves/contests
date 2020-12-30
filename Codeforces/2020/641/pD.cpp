#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int N = 1e5 + 5;
int n, k, tmp, a[N];
void solve() {
    cin >> n >> k;
    bool ok = false;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        if (tmp == k) {
            a[i] = 1;
            ok = true;
        } else {
            a[i] = tmp < k ? 0 : 2;
        }
    }
    if (!ok) {
        cout << "no\n";
        return;
    }
    if (n == 1) {
        cout << "yes\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n && j - i <= 2; j++) {
            if (a[i] > 0 && a[j] > 0) {
                cout << "yes\n";
                return;
            }
        }
    }
    cout << "no\n";
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
