// Codeforces Round #636 (Div. 3) (4/21)
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int ll;
void solve() {
    int n, t;
    cin >> n >> t;
    bool sign = t > 0;
    int tbest = t;
    ll sum = 0;
    for (int i = 1; i < n; i++) {
        cin >> t;
        if ((t > 0) != sign) {
            sum += tbest;
            tbest = t;
            sign = t > 0;
        } else {
            tbest = max(tbest, t);
        }
    }
    cout << sum + tbest << endl;
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
