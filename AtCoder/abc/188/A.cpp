#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int x, y;
    cin >> x >> y;
    if (y > x) swap(x, y);
    cout << (x - y < 3 ? "Yes\n" : "No\n");
    return 0;
}