#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, s, d;
    cin >> n >> s >> d;
    bool can = false;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        if (x < s && y > d)
            can = true;
    }
    cout << (can ? "Yes" : "No");
    return 0;
}
