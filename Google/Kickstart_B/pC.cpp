// Kickstart 2020 Round B (4/19)
#include <bits/stdc++.h>
using namespace std;
#ifndef _VSCODE_DEBUG
#define endl '\n'
#endif
typedef long long int ll;
const int s = 1e9;
int i = 0;
string input;
pair<ll, ll> move() {
    char c;
    ll x = 0, y = 0;
    i++;  // skip '('
    do {
        c = input[i];
        i++;
        if (c == 'N')
            y = y == 0 ? s - 1 : y - 1;
        else if (c == 'S')
            y = (y + 1) % s;
        else if (c == 'E')
            x = (x + 1) % s;
        else if (c == 'W')
            x = x == 0 ? s - 1 : x - 1;
        else if (c >= '1' && c <= '9') {
            ll n = c - '0';
            auto p = move();
            x = x + n * p.first;
            if (x < 0)
                x = x % s + s;
            else
                x %= s;
            y = y + n * p.second;
            if (y < 0)
                y = y % s + s;
            else
                y %= s;
        }
    } while (c != ')');
    return { x, y };
}
void solve() {
    char c;
    ll x = 0, y = 0;
    i = 0;
    getline(cin, input);
    int n = input.size();
    do {
        c = input[i];
        i++;
        if (c == 'N')
            y = y == 0 ? s - 1 : y - 1;
        else if (c == 'S')
            y = (y + 1) % s;
        else if (c == 'E')
            x = (x + 1) % s;
        else if (c == 'W')
            x = x == 0 ? s - 1 : x - 1;
        else if (c >= '1' && c <= '9') {
            ll n = c - '0';
            auto p = move();
            x = x + n * p.first;
            if (x < 0)
                x = x % s + s;
            else
                x %= s;
            y = y + n * p.second;
            if (y < 0)
                y = y % s + s;
            else
                y %= s;
        }
    } while (i < n);
    cout << x % s + 1 << " " << y % s + 1 << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _n;
    cin >> _n;
    cin.get();
    for (int i = 1; i <= _n; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
}
