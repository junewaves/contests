#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    int front = 0, back = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '1')
            back++;
        else
            break;
    }
    for (int i = 0; i < n; i++) {
        if (s[i] == '0')
            front++;
        else
            break;
    }
    string a, b;
    if (front)
        a = string(front, '0');
    if (back)
        b = string(back, '1');
    if (front + back == n)
        cout << a + b << endl;
    else 
        cout << a + '0' + b << endl;
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