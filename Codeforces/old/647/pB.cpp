#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[1024];
bool b[1024];
void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < 1024; i++) {
        memset(b, 0, 1024);
        for (int j = 0; j < n; j++) {
            b[i ^ a[j]] = 1;
        }
        bool ok = true;
        for (int j = 0; j < n && ok; j++) {
            if (!b[a[j]])
                ok = false;
        }
        if (ok) {
            cout << i << '\n';
            return;
        }
    }
    cout << -1 << '\n';
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
