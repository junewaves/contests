// https://onlinejudge.org/external/104/10405.pdf
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s1, s2;
    while (getline(cin, s1) && getline(cin, s2)) {
        int size1 = s1.size(), size2 = s2.size();
        if (size1 == 0 || size2 == 0) {
            cout << 0 << endl;
            continue;
        }
        vector<vector<int>> lcs(size1, vector<int>(size2, 0));
        for (int i = 0; i < size1; i++) {
            for (int j = 0; j < size2; j++) {
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
        // cout << lcs[size1 - 1][size2 - 1] << endl;
        int i = size1 - 1, j = size2 - 1, k = lcs[size1 - 1][size2 - 1];
        cout << k << endl;
        vector<char> ans(k);
        while (i >= 0 && j >= 0) {
            int up = i == 0 ? 0 : lcs[i - 1][j];
            int left = j == 0 ? 0 : lcs[i][j - 1];
            if (lcs[i][j] > max(up, left)) {
                ans[--k] = s1[i];
                i--;
                j--;
            } else if (lcs[i][j] == up) {
                i--;
            } else {
                j--;
            }
        }
        for (char c : ans)
            cout << c;
        cout << endl;
    }
}
