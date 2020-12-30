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
        int cnt[3][2]{}, sum = n * n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            for (int j = 0; j < n; j++) {
                if (a[i][j] == 'X')
                    cnt[(i + j) % 3][0]++;
                else if (a[i][j] == 'O')
                    cnt[(i + j) % 3][1]++;
                else 
                    sum--;
            }
        }
        int min_ops = n * n;
        array<int, 2> flip = {-1, -1};
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (i != j && cnt[i][0] + cnt[j][1] < min_ops) {
                    flip = {i, j}, min_ops = cnt[i][0] + cnt[j][1];
                }
            }
        }
        assert(min_ops * 3 <= sum);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int c = (i + j) % 3;
                if (a[i][j] == 'X' && c == flip[0]) {
                    a[i][j] = 'O';
                } else if (a[i][j] == 'O' && c == flip[1]) {
                    a[i][j] = 'X';
                }
            }
        }
        for (auto &it : a)
            cout << it << '\n';
    }
    return 0;
}