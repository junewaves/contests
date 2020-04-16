// https://onlinejudge.org/external/104/10405.pdf
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s1, s2;
    while (getline(cin, s1) && getline(cin, s2)) {
        int n1 = s1.size(), n2 = s2.size();
        if (n1 == 0 || n2 == 0) {
            cout << 0 << endl;
            continue;
        }
        vector<vector<int>> lcs(n1, vector<int>(n2, 0));
        for (int i = 0; i < n1; i++) {
            for (int j = 0; j < n2; j++) {
                if (s1[i] == s2[j]) {
                    if (i == 0 || j == 0)
                        lcs[i][j] = 1;
                    else
                        lcs[i][j] = lcs[i - 1][j - 1] + 1;
                } else {
                    int up = i == 0 ? 0 : lcs[i - 1][j];
                    int left = j == 0 ? 0 : lcs[i][j - 1];
                    lcs[i][j] = max(up, left);
                }
            }
        }
        cout << lcs[n1 - 1][n2 - 1] << endl;
        // int i = n1 - 1, j = n2 - 1, k = lcs[n1 - 1][n2 - 1];
        // cout << k << endl;
        // vector<char> ans(k);
        // while (i >= 0 && j >= 0) {
        //     int up = i == 0 ? 0 : lcs[i - 1][j];
        //     int left = j == 0 ? 0 : lcs[i][j - 1];
        //     if (lcs[i][j] > max(up, left)) {
        //         ans[--k] = s1[i];
        //         i--;
        //         j--;
        //     } else if (lcs[i][j] == up) {
        //         i--;
        //     } else {
        //         j--;
        //     }
        // }
        // for (char c : ans)
        //     cout << c;
        // cout << endl;
    }
}
