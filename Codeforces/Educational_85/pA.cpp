#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int ll;
void solve() {
    static int i = 0;
    cout << ++i << endl;
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