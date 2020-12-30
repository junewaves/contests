#include <bits/stdc++.h>
using namespace std;

constexpr int INF = 1e9 + 1000;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& it : a) 
        cin >> it;
    vector<unordered_set<int>> jumps(n); 
    {
        vector<int> first_larger_from_right(n, -1);
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j != -1;) {
                if (a[i] <= a[j]) {
                    first_larger_from_right[i] = j;
                    jumps[i].insert(j);
                    break;
                } else {
                    j = first_larger_from_right[j];
                }
            }
        }
    }
    {
        vector<int> first_larger_from_left(n, -1);
        for (int i = 1; i < n; i++) {
            for (int j = i - 1; j != -1;) {
                if (a[i] <= a[j]) {
                    first_larger_from_left[i] = j;
                    jumps[j].insert(i);
                    break;
                } else {
                    j = first_larger_from_left[j];
                }
            }
        }
    }
    {
        vector<int> first_smaller_from_right(n, -1);
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j != -1;) {
                if (a[i] >= a[j]) {
                    first_smaller_from_right[i] = j;
                    jumps[i].insert(j);
                    break;
                } else {
                    j = first_smaller_from_right[j];
                }
            }
        }
    }
    {
        vector<int> first_smaller_from_left(n, -1);
        for (int i = 1; i < n; i++) {
            for (int j = i - 1; j != -1;) {
                if (a[i] >= a[j]) {
                    first_smaller_from_left[i] = j;
                    jumps[j].insert(i);
                    break;
                } else {
                    j = first_smaller_from_left[j];
                }
            }
        }
    }
    vector<int> dp(n, INF);
    dp[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--) {
        for (int j : jumps[i]) {
            dp[i] = min(dp[i], dp[j] + 1);
        }
    }
    cout << dp[0] << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    while (tt--)
        solve();
    return 0;
}