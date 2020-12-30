#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    set<pair<int, int>> s;
    int h = n / 2, v = n - h;
    for (int i = -h; i <= h; i += 2)
        for (int j = -v; j <= v; j += 2)
            s.insert({i, j});
    if (n & 1) {
        swap(h, v);
        for (int i = -h; i <= h; i += 2)
            for (int j = -v; j <= v; j += 2)
                s.insert({i, j});
    }
    cout << s.size() << '\n';
    return 0;
}