#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    string mp[2][2] = {{"AA", "BB"}, {"AB", "BA"}};
    vector<string> ans = {"AB"};
    for (int k = 2; k <= n; k++) {
        vector<string> nxt;
        for (int i : {0, 1}) {
            for (const auto& s : ans) {
                string &ss = nxt.emplace_back();
                for (char c : s)
                    ss += mp[i][c == 'B'];
            }
        }
        string &ss = nxt.emplace_back();
        for (int i = 0; i < (1 << (k - 1)); i++)
            ss += "AB";
        ans = nxt;
    }
    cout << ans.size() << '\n';
    for (const auto& s : ans)
        cout << s << '\n';
    return 0;
}
