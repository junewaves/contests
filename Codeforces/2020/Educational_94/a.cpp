#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    int c0 = 0, c1 = 0;
    for (char c : s)
        if (c & 1)
            c1++;
        else 
            c0++;
    cout << string(n, c0 > c1 ? '0' : '1') << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}