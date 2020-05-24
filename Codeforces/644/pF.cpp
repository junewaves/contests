#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    bool done = false;
    string ans;
    // 1. pick one string -> s,
    // 2. change one of the character,
    // 3. check if s can satisify the condition
    // complexity: O(26 * n * m * m)
    for (int x = 0; x < m && !done; x++) {
        string s = a[0];
        for (int y = 0; y < 26; y++) {
            s[x] = char('a' + y);
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                int diff = 0;
                for (int j = 0; j < m; j++) {
                    if (a[i][j] != s[j])
                        diff++;
                }
                if (diff <= 1)
                    cnt++;
            }
            if (cnt == n) {
                // s is the answer
                done = true;
                ans = s;
                break;
            }
        }
    }
    if (!done)
        ans = "-1";
    cout << ans << '\n';
    return;
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
// abbbbbb

// babbbbb
// abbbbbb
// abbbbbb
// abbbbbb
// abbbbbb
// abbbbbb
