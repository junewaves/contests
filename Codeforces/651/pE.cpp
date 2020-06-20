#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    int cnt1 = 0, cnt2 = 0;
    set<int> diff;
    for (int i = 0; i < n; i++) {
        if (s1[i] == '1')
            cnt1++;
        if (s2[i] == '1')
            cnt2++;
        if (s1[i] != s2[i]) {
            diff.insert(i);
        }
    }
    if (cnt1 != cnt2) {
        cout << "-1\n";
        return;
    }
    if (diff.empty()) {
        cout << "0\n";
        return;
    }
    int ans = 0;
    while (!diff.empty()) {
        char prev = s1[*diff.begin()];
        vector<int> rm;
        rm.push_back(*diff.begin());
        for (auto it = ++diff.begin(); it != diff.end(); it++) {
            if (s1[*it] != prev) {
                prev = (prev == '0' ? '1' : '0');
                rm.push_back(*it);
            }
        }
        if ((int)rm.size() & 1) {
            rm.pop_back();
        }
        for (int i : rm) {
            diff.erase(i);
        }
        ans++;
        if (rm.size() <= 2)
            break;
    }
    if (!diff.empty())
        ans += (int)diff.size() / 2;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}