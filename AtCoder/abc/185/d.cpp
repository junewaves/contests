#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    if (m == 0) {
        cout << "1\n";
        return 0;
    }
    vector<int> a(m);
    for (int &it : a) cin >> it;
    sort(a.begin(), a.end());
    vector<int> b;
    int start = 0;
    for (int it : a) {
        int diff = it - start - 1;
        if (diff > 0) b.push_back(diff);
        start = it;
    }
    if (n - start - 1 > 0)
        b.push_back(n - start);
    if (b.empty()) {
        cout << "0\n";
        return 0;
    }
    int stamp = *min_element(b.begin(), b.end());
    int ans = 0;
    for (int &it : b)
        ans += (it + stamp - 1) / stamp;
    cout << ans << '\n';
}
