#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> ans;

void gogo(int base, int n) {
    assert(__builtin_popcount(n) == 1);
    int gn = 1;
    int x = n >> 1;
    while (x) {
        for (int i = 0; i < n; i += gn * 2) {
            for (int j = 0; j < gn; j++) {
                ans.emplace_back(base + i + j, base + i + j + gn);
            }
        }
        x >>= 1;
        gn <<= 1;
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    if (n <= 2) {
        cout << 0 << '\n';
        return 0;
    }
    int mxn = 1;
    while (mxn * 2 < n) mxn *= 2;
    // cout << mxn << endl;
    gogo(0, mxn);
    gogo(n - mxn, mxn);

    cout << ans.size() << '\n';
    for (auto p : ans)
        cout << p.first + 1 << ' ' << p.second + 1 << '\n';
    return 0;
}