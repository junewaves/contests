#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<string> a(n);
        int cnt[3]{};
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            for (int j = 0; j < n; j++)
                if (a[i][j] == 'X')
                    cnt[(i + j) % 3]++;
        }
        int flip = min_element(cnt, cnt + 3) - cnt;
        int sum = accumulate(cnt, cnt + 3, 0);
        assert(cnt[flip] * 3 <= sum);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if ((i + j) % 3 == flip && a[i][j] == 'X')
                    a[i][j] = 'O';
        for (auto &it : a)
            cout << it << '\n';
    }
    return 0;
}