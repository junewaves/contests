// UVa 624 - CD
#include <bits/stdc++.h>
using namespace std;
#ifndef _LOCAL_DEBUG
#define endl '\n'
#endif
int N, n_tracks, tracks[21];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> N >> n_tracks) {
        for (int i = 1; i <= n_tracks; i++)
            cin >> tracks[i];
        vector<vector<int>> s(n_tracks + 1, vector<int>(N + 1));
        for (int i = 0; i <= n_tracks; i++)
            for (int j = 0; j <= N; j++)
                s[i][j] = j == 0 ? 0 : -1;
        for (int i = 1; i <= n_tracks; i++) {
            for (int j = 0; j <= N; j++) {
                if (j >= tracks[i] && s[i - 1][j - tracks[i]] != -1)
                    s[i][j] = max(s[i - 1][j], s[i - 1][j - tracks[i]] + 1);
                else
                    s[i][j] = s[i - 1][j];
            }
        }
        int i = n_tracks, sum = 0;
        for (int j = N; j >= 0;) {
            if (s[i][j] > 0) {
                while (s[i - 1][j] > -1)
                    i--;
                cout << tracks[i] << " ";
                j -= tracks[i];
                sum += tracks[i];
            } else {
                j--;
            }
        }
        cout << "sum:" << sum << endl;
    }
}
