#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int v, t, s, d;
    cin >> v >> t >> s >> d;
    if (t * v <= d && d <= s * v)
        cout << "No\n";
    else
        cout << "Yes\n";
    return 0;
}
