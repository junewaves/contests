#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> num(n);
    vector<vector<int>> p(n);
    for (int i = 0; i < n; i++)
        cin >> num[i];
    for (int i = 0; i < n; i++) {
        int l = i - num[i], r = i + num[i];
        while (r < n || l >= 0) {
            if (l >= 0 && num[l] > num[i]) {
                p[num[i] - 1].push_back(num[l]);
            }
            if (r < n && num[r] > num[i]) {
                p[num[i] - 1].push_back(num[r]);
            }
            l -= num[i];
            r += num[i];
        }
    }
    vector<char> ans(n);
    for (int i = n - 1; i >= 0; i--) {
        if (p[i].size() == 0) {
            ans[i] = 'B';
            continue;
        }
        ans[i] = 'B';
        for (int t : p[i]) {
            if (ans[t - 1] == 'B') {
                ans[i] = 'A';
                break;
            }
        }
    }
    for (int i : num) {
        cout << ans[i - 1];
    }
    cout << '\n';
}