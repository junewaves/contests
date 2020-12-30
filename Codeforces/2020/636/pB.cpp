// Codeforces Round #636 (Div. 3) (4/21)
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int ll;
void solve() {
    int n;
    cin >> n;
    int a = n / 2;
    if (a & 1) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    vector<int> ans(n);
    for (int i = 0; i < a; i++) {
        cout << (i + 1) * 2 << " ";
    }
    for (int i = 0; i < a - 1; i++) {
        cout << 1 + (i * 2) << " ";
    }
    cout << 3 * a - 1 << endl;
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
