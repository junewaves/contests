#include <bits/stdc++.h>
using namespace std;
int ans, n, k;
/*
struct Trie {
    Trie* next[26];
    int count;
    Trie() : count(0) { memset(next, 0, sizeof(next)); }
    // Inserts a word into the trie.
    void insert(string word) {
        int s = word.size(), i = 0;
        Trie* t = this;
        while (i < s) {
            int c = word[i] - 'A';
            if (!t->next[c])
                t->next[c] = new Trie();
            t = t->next[c];
            t->count++;
            i++;
        }
    }
};
void dfs(Trie* t) {
    ans += t->count / k;
    for (int i = 0; i < 26; i++) {
        if (t->next[i]) {
            dfs(t->next[i]);
        }
    }
}
*/
const int mxN = 2e6 + 1;
int t[mxN][26], cnt[mxN];
void dfs(int u = 0) {
    ans += cnt[u] / k;
    for (int i = 0; i < 26; i++) {
        if (t[u][i]) {
            dfs(t[u][i]);
        }
    }
}
void solve() {
    cin >> n >> k;
    string s;
    // Trie* t = new Trie();
    int m = 1;
    for (int i = 0; i < n; i++) {
        cin >> s;
        // t->insert(s);
        int u = 0;
        for (char c : s) {
            int j = c - 'A';
            if (!t[u][j])
                t[u][j] = m++;
            u = t[u][j];
            cnt[u]++;
        }
    }
    ans = 0;
    dfs(0);
    cout << ans << '\n';
    /*
    for (int i = 0; i < m; i++) {
        cout << cnt[i] << " ";
    }
    cout << '\n';
    */
    memset(t, 0, m * sizeof(t[0]));
    memset(cnt, 0, m * 4);
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
