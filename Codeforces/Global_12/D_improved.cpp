#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> freq(n);
        bool flag = true;
        for (int &it : a) {
            cin >> it;
            --it;
            if (++freq[it] > 1)
                flag = false;
        }
        string ans(n - 1, '0');
        int L = 0, R = n - 1;
        for (int k = 0; k < n - 1; k++) {
            ans[k] += freq[k] > 0;
            if (freq[k] != 1) 
                break;
            if (a[L] == k) 
                L++;
            else if (a[R] == k) 
                R--;
            else 
                break;
        }
        ans += char('0' + flag);
        reverse(ans.begin(), ans.end());
        cout << ans << '\n';
    }
    return 0;
}