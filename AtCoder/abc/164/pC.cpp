#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    unordered_set<string> s;
    int n;
    cin >> n;
    while (n--) {
        string ss;
        cin >> ss;
        s.insert(ss);
    }
    cout << s.size() << endl;
}
