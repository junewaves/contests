#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int a, b, c;
        cin >> a >> b >> c;
        div_t r = div(a + b + c, 9);
        cout << ((r.rem == 0 && min({a, b, c}) >= r.quot) ? "YES\n" : "NO\n");
    }
    return 0;
}