#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int N = 1e4;
// Don't know why cin/cout will fail(WA) but sacnf/printf get AC
void solve() {
    pair<int, char> d[26];
    for (int i = 0; i < 26; i++) {
        d[i].first = 0;
        d[i].second = 'A' + i;
    }
    unordered_set<char> appeared;
    int u, n;
    char s[17];
    scanf("%d", &u);
    for (int i = 0; i < N; i++) {
        scanf("%d%s", &n, s);
        for (size_t j = 0; j < strlen(s); j++) {
            appeared.insert(s[j]);
        }
        d[s[0] - 'A'].first++;
    }
    for (char c : appeared) {
        if (d[c - 'A'].first == 0) {
            printf("%c", d[c - 'A'].second);
        }
    }
    sort(d, d + 26, [](const pair<int, char>& x, const pair<int, char>& y) {
        return x.first > y.first;
    });
    for (int i = 0; i < 9; i++) {
        // cout << d[i].first << ", " << d[i].second << endl;
        printf("%c", d[i].second);
    }
    puts("");
}
int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int _n;
    // cin >> _n;
    scanf("%d", &_n);
    for (int _cn = 1; _cn <= _n; _cn++) {
        printf("Case #%d: ", _cn);
        solve();
    }
    return 0;
}