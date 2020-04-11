// Code Jam Round 1A (4/11)
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int ll;
int _n, r, c;
ll level, sum;
bool eliminate(vector<vector<int>>& room) {
    bool e = false;
    vector<pair<int, int>> eli;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            // calc compass and nei
            if (room[i][j] != -1) {
                int compass = 0, nei = 0;
                if (i > 0) {
                    int p = i - 1;
                    while (p >= 0 && room[p][j] == -1) {
                        p--;
                    }
                    if (p >= 0) {
                        compass += room[p][j];
                        nei++;
                    }
                }
                if (j > 0) {
                    int p = j - 1;
                    while (p >= 0 && room[i][p] == -1) {
                        p--;
                    }
                    if (p >= 0) {
                        compass += room[i][p];
                        nei++;
                    }
                }
                if (i < r - 1) {
                    int p = i + 1;
                    while (p < r && room[p][j] == -1) {
                        p++;
                    }
                    if (p < r) {
                        compass += room[p][j];
                        nei++;
                    }
                }
                if (j < c - 1) {
                    int p = j + 1;
                    while (p < c && room[i][p] == -1) {
                        p++;
                    }
                    if (p < c) {
                        compass += room[i][p];
                        nei++;
                    }
                }
                if (room[i][j] * nei < compass) {
                    e = true;
                    sum -= room[i][j];
                    eli.emplace_back(i, j);
                }
            }
        }
    }
    for (auto& pp : eli) {
        room[pp.first][pp.second] = -1;
    }
    return e;
}
void solve() {
    cin >> r >> c;
    vector<vector<int>> room(r, vector<int>(c));
    // vector<vector<int>> compass(r, vector<int>(c, 0));
    // vector<vector<int>> nei(r, vector<int>(c, 0));
    level = 0, sum = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> room[i][j];
            sum += room[i][j];
        }
    }
    level = sum;
    while (eliminate(room)) {
        level += sum;
    }
    cout << level << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> _n;
    for (int _cn = 1; _cn <= _n; _cn++) {
        cout << "Case #" << _cn << ": ";
        solve();
    }
    return 0;
}