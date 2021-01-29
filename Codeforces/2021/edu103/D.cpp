#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    const char* dir = "RL";
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> ans(n + 1, 1);
        for (int i = 0, j; i < n; i++) {
            for (j = 0; i + j < n; j++)
                if (s[i + j] != dir[j % 2])
                    break;

            for (int k = i; k < i + j; k += 2)
                ans[k] += j - (k - i);
            i += j - (j != 0);
        }
        for (int i = n, j; i > 0; i--) {
            for (j = 1; i - j >= 0; j++)
                if (s[i - j] != dir[j % 2])
                    break;

            j--;
            for (int k = i; k > i - j; k -= 2)
                ans[k] += j - (i - k);
            i -= j - (j != 0);
        }
        for (int i = 0; i <= n; i++)
            cout << ans[i] << ' ';
        cout << '\n';
    }
    return 0;
}
