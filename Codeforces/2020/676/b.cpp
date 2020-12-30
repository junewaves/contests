#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];
    char a = s[0][1], b = s[1][0];
    char c = s[n - 1][n - 2], d = s[n - 2][n - 1];
    vector<pair<int, int>> answer;
    if (a == b) {
        if (c == a)
            answer.emplace_back(n, n - 1);
        if (d == a)
            answer.emplace_back(n - 1, n);
    } else if (c == d) {
        if (c == a)
            answer.emplace_back(1, 2);
        if (c == b)
            answer.emplace_back(2, 1);
    } else {
        answer.emplace_back(2, 1);
        if (c == a)
            answer.emplace_back(n, n - 1);
        if (d == a)
            answer.emplace_back(n - 1, n);
    }
    cout << answer.size() << '\n';
    for (auto [x, y] : answer)
        cout << x << ' ' << y << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}