#include <bits/stdc++.h>
using namespace std;

string ans;
bool is_better(const string& a) {
    if (ans == "-1")
        return true;
    int na = a.size(), nb = ans.size();
    if (na != nb)
        return na < nb;
    for (int i = 0; i < na; i++) {
        if (a[i] != ans[i])
            return a[i] < ans[i];
    }
    return false;
}

void solve() {
    int n, k;
    ans = "-1";
    cin >> n >> k;
    for (int i = 0; i <= 9; i++) {  // iter through last digit
        int cnt9 = i + k < 10 ? 0 : n / 9;
        for (int j = 0; j <= cnt9; j++) {  // # of 9's in all the numbers
            if (i + k >= 10 && j == 0)
                continue;
            int curSum = (i + i + k) * (k + 1) / 2;
            if (j != 0) {
                int before = 10 - i;
                int after = k + 1 - before;
                curSum = (i + 9) * before / 2 + before * 9 * (j - 1) +
                         (1 + after) * after / 2;
            }
            curSum = n - curSum;
            if (curSum < 0 || curSum % (k + 1) != 0)
                continue;
            string num = {char('0' + i)};
            for (int z = 0; z < j - 1; z++)
                num += '9';
            curSum /= k + 1;
            int maxNum = (i + k >= 10) ? 8 : 9;
            while (curSum) {
                int d = min(curSum, maxNum);
                maxNum = 9;
                curSum -= d;
                num.push_back(char('0' + d));
            }
            reverse(num.begin(), num.end());
            if (is_better(num)) 
                ans = num;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
}