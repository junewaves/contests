#include <bits/stdc++.h>
using namespace std;

constexpr int sz = 531450;  // 27 ^ 4 + 9
int idx_of[sz];
int str_value(const string& s) {
    int res = 0;
    for (int i = 0; i < int(s.size()); i++)
        res = res * 27 + (s[i] == '_' ? 26 : s[i] - 'a');
    return res;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    memset(idx_of, -1, sizeof(idx_of));
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> pattern(n), query(m);
    vector<int> match_idx(m), deg1(n), deg2(n);
    vector<vector<int>> adjp(n), adjq(m);

    for (int i = 0; i < n; i++) {
        cin >> pattern[i];
        idx_of[str_value(pattern[i])] = i;
    }

    int matched = 0;
    for (int j = 0; j < m; j++) {
        cin >> query[j] >> match_idx[j];
        match_idx[j]--;
        deg1[match_idx[j]]++;
        // generate all matching patterns
        for (int ms = 0; ms < (1 << k); ms++) {
            string tmp(k, '_');
            for (int z = 0; z < k; z++)
                if (ms & (1 << z))
                    tmp[z] = query[j][z];
            int val = str_value(tmp);
            if (idx_of[val] != -1) {
                deg2[idx_of[val]]++;
                adjq[j].push_back(idx_of[val]);
                if (idx_of[val] == match_idx[j]) {
                    matched++;
                    adjp[idx_of[val]].push_back(j);
                }
            }
        }
    }
    if (matched < m) {
        cout << "NO\n";
        return 0;
    }

    vector<int> que;
    for (int i = 0; i < n; i++)
        if (deg1[i] == deg2[i])
            que.push_back(i);

    for (int z = 0; z < int(que.size()); z++) {
        int i = que[z];
        for (int j : adjp[i]) {
            for (int x : adjq[j]) {
                if (i != x) {
                    deg2[x]--;
                    if (deg1[x] == deg2[x]) {
                        que.push_back(x);
                    }
                }
            }
        }
    }

    if (int(que.size()) == n) {
        cout << "YES\n";
        for (int x : que) 
            cout << x + 1 << ' ';
        cout << '\n';
    } else {
        cout << "NO\n";
    }
    return 0;
}
