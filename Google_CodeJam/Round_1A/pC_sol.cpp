#include <bits/stdc++.h>
using namespace std;
#ifndef _LOCAL_DEBUG
#define endl '\n'
#endif
typedef long long ll;
int R, C;
// distance to up/down/left/right compass neighbor
// 0 = no neighbor in this direction
struct Distance {
    int u, d, l, r;
};
unordered_set<int> first_elimination(vector<vector<int>>& skl,
                                     vector<vector<Distance>>& cmp,
                                     ll& skill_sum) {
    unordered_set<int> check;
    unordered_set<int> eli;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            int num = 0, sum = 0;
            if (cmp[i][j].u > 0) {
                num++;
                sum += skl[i - cmp[i][j].u][j];
            }
            if (cmp[i][j].d > 0) {
                num++;
                sum += skl[i + cmp[i][j].d][j];
            }
            if (cmp[i][j].l > 0) {
                num++;
                sum += skl[i][j - cmp[i][j].l];
            }
            if (cmp[i][j].r > 0) {
                num++;
                sum += skl[i][j + cmp[i][j].r];
            }
            // check if (i, j) will be eliminated
            if (skl[i][j] * num < sum) {
                eli.insert(i * C + j);
                skill_sum -= skl[i][j];
            }
        }
    }
    for (int e : eli) {
        int i = e / C, j = e % C;
        Distance& E = cmp[i][j];
        int gap1 = ((E.u * E.d == 0) ? 0 : E.u + E.d);
        int gap2 = ((E.l * E.r == 0) ? 0 : E.l + E.r);
        if (E.u > 0) {
            cmp[i - E.u][j].d = gap1;
            check.insert((i - E.u) * C + j);
        }
        if (E.d > 0) {
            cmp[i + E.d][j].u = gap1;
            check.insert((i + E.d) * C + j);
        }
        if (E.l > 0) {
            cmp[i][j - E.l].r = gap2;
            check.insert(i * C + (j - E.l));
        }
        if (E.r > 0) {
            cmp[i][j + E.r].l = gap2;
            check.insert(i * C + (j + E.r));
        }
    }
    for (int e : eli) {
        if (check.count(e))
            check.erase(e);
    }
    return check;
}
void elimination(unordered_set<int>& chk, vector<vector<int>>& skl,
                 vector<vector<Distance>>& cmp, ll& skill_sum) {
    unordered_set<int> eli;
    for (int c : chk) {
        int i = c / C, j = c % C;
        int num = 0, sum = 0;
        if (cmp[i][j].u > 0) {
            num++;
            sum += skl[i - cmp[i][j].u][j];
        }
        if (cmp[i][j].d > 0) {
            num++;
            sum += skl[i + cmp[i][j].d][j];
        }
        if (cmp[i][j].l > 0) {
            num++;
            sum += skl[i][j - cmp[i][j].l];
        }
        if (cmp[i][j].r > 0) {
            num++;
            sum += skl[i][j + cmp[i][j].r];
        }
        // check if (i, j) will be eliminated
        if (skl[i][j] * num < sum) {
            eli.insert(c);
            skill_sum -= skl[i][j];
        }
    }
    chk.clear();
    for (int e : eli) {
        int i = e / C, j = e % C;
        Distance& E = cmp[i][j];
        int gap1 = ((E.u * E.d == 0) ? 0 : E.u + E.d);
        int gap2 = ((E.l * E.r == 0) ? 0 : E.l + E.r);
        if (E.u > 0) {
            cmp[i - E.u][j].d = gap1;
            chk.insert((i - E.u) * C + j);
        }
        if (E.d > 0) {
            cmp[i + E.d][j].u = gap1;
            chk.insert((i + E.d) * C + j);
        }
        if (E.l > 0) {
            cmp[i][j - E.l].r = gap2;
            chk.insert(i * C + (j - E.l));
        }
        if (E.r > 0) {
            cmp[i][j + E.r].l = gap2;
            chk.insert(i * C + (j + E.r));
        }
    }
    for (int e : eli) {
        if (chk.count(e))
            chk.erase(e);
    }
}
void solve() {
    cin >> R >> C;
    vector<vector<int>> skill_level(R, vector<int>(C));
    vector<vector<Distance>> compass(R, vector<Distance>(C, { 1, 1, 1, 1 }));
    ll sum = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> skill_level[i][j];
            sum += skill_level[i][j];
            if (i == 0)
                compass[i][j].u = 0;
            if (j == 0)
                compass[i][j].l = 0;
            if (i == R - 1)
                compass[i][j].d = 0;
            if (j == C - 1)
                compass[i][j].r = 0;
        }
    }
    ll level_sum = sum;
    unordered_set<int> check = first_elimination(skill_level, compass, sum);
    while (!check.empty()) {
        level_sum += sum;
        elimination(check, skill_level, compass, sum);
    }
    cout << level_sum << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _n;
    cin >> _n;
    for (int _cn = 1; _cn <= _n; _cn++) {
        cout << "Case #" << _cn << ": ";
        solve();
    }
}