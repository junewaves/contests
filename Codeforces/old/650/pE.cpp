#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> s(26, 0);
    char c;
    for (int i = 0; i < n; i++) {
        cin >> c;
        s[c - 'a']++;
    }
    sort(s.begin(), s.end(), greater<int>());
    for (int cc : s)
        cout << cc << ' ';
    cout << '\n';
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
