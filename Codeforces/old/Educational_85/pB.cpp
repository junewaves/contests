#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int ll;

ll n, x;
ll p[100005];
void solve() {
    memset(p, 0, sizeof(0));
    cin >> n >> x;
    // int cnt;
    ll cnt = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        if (p[i] >= x) {
            cnt++;
        }
        sum += p[i];
    }
    if (cnt == 0) {
        cout << 0 << endl;
        return;
    }
    sort(p, p + n);
    int j = 0;
    for (ll i = n; i >= cnt; i--, j++) {
        if (sum / i >= x) {
            cnt = i;
            break;
        }
        sum -= p[j];
    }
    cout << cnt << endl;
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