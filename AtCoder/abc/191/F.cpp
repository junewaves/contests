#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &it : a) cin >> it;
    int min_a = *min_element(a.begin(), a.end());
    unordered_map<int, int> memo;
    for (int x : a) {
        for (int y = 1; y < min_a && y * y <= x; y++) {
            if (x % y == 0) {
                memo[y] = gcd(memo[y], x);
                if (int z = x / y; z < min_a) {
                    memo[z] = gcd(memo[z], x);
                }
            }
        }
    }
    int ans = 1;
    for (auto &p : memo)
        if (p.first == p.second)
            ans++;
    cout << ans << '\n';
    return 0;
}
