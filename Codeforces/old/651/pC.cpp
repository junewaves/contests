#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    string p1 = "Ashishgup", p2 = "FastestFinger";
    if (n == 1) {
        cout << p2 << endl;
        return;
    } 
    if (n % 2 != 0 || n == 2) {
        cout << p1 << endl;
        return;
    } 
    int b = n & -n;
    int c = n / b;
    bool prime = true;
    for (int i = 3; i * i <= c; i += 2) {
        if (c % i == 0) {
            prime = false;
            break;
        }
    }
    // cout << b << " " << prime << endl;
    if (c == 1 || (b == 2 && prime)) {
        cout << p2 << endl;
        return;
    } else {
        cout << p1 << endl;
        return;
    }
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