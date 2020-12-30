#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
int a[30], b[30];
void solve() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    sort(a, a + n, greater<int>());
    sort(b, b + n, greater<int>());
    int l = 0, r = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        if (r < k && a[l] < b[r]) {
            sum += b[r];
            r++;
        } else {
            sum += a[l];
            l++;
        }
    }
    cout << sum << endl;
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
