// Codeforces Round #636 (Div. 3) (4/21)
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> num(n);
    vector<int> can(2 * k + 2, 0);
    can[0] = n;
    for (int i = 0; i < n; i++)
        cin >> num[i];
    for (int i = 0; i < n / 2; i++) {
        int a = min(num[i], num[n - i - 1]);
        int b = max(num[i], num[n - i - 1]);
        can[1 + a]--;
        can[a + b]--;
        can[a + b + 1]++;
        can[b + k + 1]++;
    }
    int ans = n, curr = 0;
    for (int m : can) {
        curr += m;
        ans = min(ans, curr);
    }
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
