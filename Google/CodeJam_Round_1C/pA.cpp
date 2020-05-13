#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
void solve() {
    int x, y;
    string s;
    cin >> x >> y >> s;
    if (x == 0 && y == 0) {
        cout << 0 << endl;
        return;
    }
    int n = s.size();
    for (int i = 1; i <= n; i++) {
        char c = s[i - 1];
        if (c == 'S')
            y -= 1;
        else if (c == 'N')
            y += 1;
        else if (c == 'W')
            x -= 1;
        else
            x += 1;
        if (abs(x) + abs(y) <= i) {
            cout << i << endl;
            return;
        }
    }
    cout << "IMPOSSIBLE\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _n;
    cin >> _n;
    for (int _cn = 1; _cn <= _n; _cn++) {
        cout << "Case #" << _cn << ": ";
        solve();
    }
    return 0;
}