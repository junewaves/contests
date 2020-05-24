#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
void solve() {
    int a, b;
    cin >> a >> b;
    if (a < b)
        swap(a, b);
    int s = max(a, 2 * b);
    cout << s * s << '\n';
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
