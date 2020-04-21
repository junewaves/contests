// Codeforces Round #636 (Div. 3) (4/21)
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> num(n);
    vector<int> can(2 * k + 1, n);
    for (int i = 0; i < n; i++)
        cin >> num[i];
    for (int i = 0; i < n / 2; i++) {
        int a = max(num[i], num[n - i - 1]);
        int b = min(num[i], num[n - i - 1]);
        for (int j = b + 1; j <= k + a; j++)
            can[j] -= ((j == a + b) ? 2 : 1);
    }
    for (int i : can)
        cout << i << " ";
    cout << endl;
    int ans = n;
    for (int m : can)
        ans = min(ans, m);
    cout << ans << endl;
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
