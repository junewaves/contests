#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    int ans = INT_MAX;
    for (int i = 0; i + m - 1 < n; i++) {
        int cnt = 0;
        for (int j = 0; j < m; j++) {
            if (s[i + j] != t[j]) 
                cnt++;
        }
        ans = min(ans, cnt);
    }
    cout << ans;
    return 0;
}