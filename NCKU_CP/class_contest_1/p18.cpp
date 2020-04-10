#include <bits/stdc++.h>
using namespace std;
// problem source: https://judge.csie.ncku.edu.tw/problems/18
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    int n, act;
    unordered_set<string> dict;
    stack<string> last_insert;
    cin >> n;
    while (n--) {
        cin >> act;
        if (act == 1) {
            cin >> s;
            dict.insert(s);
            last_insert.push(s);
        } else if (act == 2) {
            if (!last_insert.empty()) {
                dict.erase(last_insert.top());
                last_insert.pop();
            }
        } else {
            cin >> s;
            if (dict.count(s))
                cout << "Y";
            else
                cout << "N";
        }
    }
    cout << '\n';
}