#include <bits/stdc++.h>
using namespace std;

struct compressed {
    string pre, suf;
    int len = 0;
    bool increase = false;

    void add(char c) {
        if (len && c != pre[0])
            increase = c < pre[0];
        len++;
        pre = c + pre;
        if ((int)suf.size() < 2) suf = c + suf;
        if ((int)pre.size() > 10) pre.resize(10);
    }
    friend ostream& operator<<(ostream& os, const compressed& s) {
        os << s.len << " ";
        if (s.len > 10)
            os << s.pre.substr(0, 5) << "..." << s.suf;
        else
            os << s.pre;
        return os;
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    string s;
    cin >> s;
    int n = s.size();
    vector<compressed> ans(n + 1);
    ans[n - 1].add(s[n - 1]);
    for (int i = n - 2; i >= 0; i--) {
        char c = s[i];
        if (c == s[i + 1]) {
            ans[i] = ans[i + 2];
            if (ans[i].len && (c < ans[i].pre[0] || (c == ans[i].pre[0] && ans[i].increase))) {
                ans[i].add(c);
                ans[i].add(c);
            }
        } else {
            ans[i] = ans[i + 1];
            ans[i].add(s[i]);
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << '\n';
    }
    return 0;
}