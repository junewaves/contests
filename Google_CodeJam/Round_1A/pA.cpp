#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int ll;
// Code Jam Round 1A
int _n;
void solve() {
    static int i = 0;
    cout << ++i << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> _n;
    for (int _cn = 1; _cn <= _n; _cn++) {
        cout << "Case #" << _cn << ": ";
        solve();
    }
    return 0;
}