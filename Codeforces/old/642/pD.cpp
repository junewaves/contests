#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pair_i;
const int N = 2e5 + 1;
int n;
void solve() {
    cin >> n;
    vector<int> a(n + 1);
    auto cmp = [](const pair_i& x, const pair_i& y) {
        if (x.second - x.first == y.second - y.first)
            return x.first > y.first;
        return x.second - x.first < y.second - y.first;
    };
    priority_queue<pair_i, vector<pair_i>, decltype(cmp)> q(cmp);
    q.emplace(1, n);
    int l, r, m, i = 1;
    while (!q.empty()) {
        tie(l, r) = q.top();
        q.pop();
        if ((r - l + 1) % 2)
            m = (l + r) / 2;
        else
            m = (l + r - 1) / 2;
        a[m] = i++;
        if (m + 1 <= r)
            q.emplace(m + 1, r);
        if (l <= m - 1)
            q.emplace(l, m - 1);
    }
    for (int x = 1; x <= n; x++)
        cout << a[x] << " ";
    cout << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _n;
    cin >> _n;
    while (_n--) {
        solve();
    }
    return 0;
}
