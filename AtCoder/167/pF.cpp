#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
bool check(const vector<pair<int, int>>& s) {
    int h = 0;
    for (const auto& p : s) {
        if (h + p.first < 0)
            return false;
        h += p.second;
    }
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, total = 0;
    cin >> n;
    vector<pair<int, int>> ls, rs;
    for (int i = 0; i < n; i++) {
        string tmp;
        int l = 0, b = 0;
        cin >> tmp;
        for (const char& c : tmp) {
            if (c == '(')
                l++;
            else
                l--;
            b = min(b, l);
        }
        if (l > 0)
            ls.emplace_back(b, l);
        else
            rs.emplace_back(b - l, -l);
        total += l;
    }
    sort(ls.rbegin(), ls.rend());
    sort(rs.rbegin(), rs.rend());
    if (check(ls) && check(rs) && total == 0)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
