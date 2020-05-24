#include <bits/stdc++.h>
using namespace std;
using std::cout;
typedef long long ll;
void solve() {
    int n, k;
    cin >> n >> k;
    vector<string> strs(n);
    vector<bool> chk(n);
    vector<map<char, int>> cnt(n);
    for (int i = 0; i < n; i++)
        cin >> strs[i];
    if (k == 1)
        cout << strs[0] << '\n';
    for (int j = 0; j < k; j++) {
        for (string s : strs) {
            cnt[j][s[j]]++;
        }
    }
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
