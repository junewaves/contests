#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using mint = atcoder::modint1000000007;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int &it : a) cin >> it;
    int sum = accumulate(a.begin(), a.end(), 0);
    if (sum > m) {
        cout << "0\n";
        return 0;
    }
    mint num = m + n, den = 1, ans = 1;
    for (int i = 1; i <= sum + n; i++) {
        ans = ans * num / den;
        num--, den++;
    }
    cout << ans.val() << '\n';
    return 0;
}