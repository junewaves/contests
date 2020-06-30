#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    string s;
    cin >> s;
    int c1 = 0, c0 = 0;
    for (char c : s) {
        if (c == '1')
            c1++;
        else
            c0++;
    }
    int x = min(c1, c0);
    if (x & 1)
        cout << "DA" << endl;
    else 
        cout << "NET" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}