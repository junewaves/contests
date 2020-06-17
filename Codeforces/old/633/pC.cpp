// Codeforces Round #633 (Div. 2) (4/12)
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int ll;
void solve() {
    int n, n_max = INT_MIN, tmp, d_max = 0, t = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        if (tmp > n_max) {
            n_max = tmp;
        }
        int p = n_max - tmp;
        d_max = max(p, d_max);
    }
    while (d_max > 0) {
        d_max >>= 1;
        t++;
    }
    cout << t << endl;
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