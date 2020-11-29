#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, x;
    cin >> n >> x;
    string s;
    cin >> s;
    for (char c : s) {
        if (c == 'o')
            x++;
        else if (x > 0)
            x--;
    }
    cout << x << '\n';
    return 0;
}