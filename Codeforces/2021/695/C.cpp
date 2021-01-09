#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n[3];
    for (int i = 0; i < 3; i++) cin >> n[i];
    vector<int> a[3];
    int mn[3];
    int64_t sum = 0, mn2[3];
    for (int i = 0; i < 3; i++) {
        a[i].assign(n[i], 0);
        for (int &it : a[i]) cin >> it;
        sort(a[i].begin(), a[i].end());
        mn[i] = a[i][0];
        mn2[i] = accumulate(a[i].begin() + 1, a[i].end(), 0LL);
        sum += mn2[i] + mn[i];
    }
    int s = min_element(mn, mn + 3) - mn;
    for (int i = 0; i < 3; i++) 
        if (i != s) mn2[i] = mn[i]; 
    int64_t ans = sum - (*min_element(mn2, mn2 + 3) + mn[s]) * 2;
    if (count(n, n + 3, 1) >= 1) {
        vector<int> x;
        for (int i = 0; i < 3; i++)
            if (n[i] == 1)
                x.push_back(mn[i]);
        ans = max(ans, sum - *min_element(x.begin(), x.end()) * 2);
    }
    cout << ans << '\n';
    return 0;
}