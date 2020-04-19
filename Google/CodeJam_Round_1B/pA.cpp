// Code Jam Round 1B (4/19)
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
int bits(int x) {
    int b = 0;
    while (x > 0) {
        x >>= 1;
        b++;
    }
    return b;
}
string sol(int x, int y, int n) {
    string s;
    int g = abs(x) + abs(y);
    if ((g & (g + 1)) == 0) {
        int _x = abs(x), _y = abs(y);
        while (_x > 0 || _y > 0) {
            if (_x & 1)
                s += x > 0 ? "E" : "W";
            else
                s += y > 0 ? "N" : "S";
            _x >>= 1;
            _y >>= 1;
        }
        return s;
    }
    if (abs(x) == 1 && abs(y) == 1)
        return "I";
    if (abs(x) < abs(y)) {
        int _x = x > 0 ? x - pow(2, n - 1) : x + pow(2, n - 1);
        int _y = y > 0 ? y - pow(2, n) : y + pow(2, n);
        s = sol(_x, _y, n - 2);
        if (s != "I") {
            s += x > 0 ? "E" : "W";
            s += y > 0 ? "N" : "S";
        }
    } else {
        int _x = x > 0 ? x - pow(2, n) : x + pow(2, n);
        int _y = y > 0 ? y - pow(2, n - 1) : y + pow(2, n - 1);
        s = sol(_x, _y, n - 2);
        if (s != "I") {
            s += y > 0 ? "N" : "S";
            s += x > 0 ? "E" : "W";
        }
    }
    return s;
}

void solve() {
    int x, y;
    cin >> x >> y;
    int b = bits(abs(x) + abs(y)) - 1;
    string s = sol(x, y, b);
    // if (x >= y)
    //     s += sol(pow(2, b) - x, pow(x, b - 1) - y);
    if (s == "I")
        cout << "IMPOSSIBLE\n";
    else
        cout << s << endl;
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