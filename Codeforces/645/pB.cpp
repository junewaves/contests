#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& it : a)
        cin >> it;
    sort(a.begin(), a.end());
    int ans = n - 1;
    while (ans >= 0 && a[ans] > ans + 1)
        --ans;
    cout << ans + 2 << '\n';
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
