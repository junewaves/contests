#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> group, groupSize;
int Find(int v) {
    if (v == group[v])
        return v;
    group[v] = Find(group[v]);
    return group[v];
}
void Union(int u, int v) {
    int gu = Find(u), gv = Find(v);
    group[gv] = gu;
    groupSize[gu] += groupSize[gv] == 0 ? 1 : groupSize[gv];
}
inline int getGroupSize(int v) {
    return groupSize[Find(v)];
}
int main() {
    int n, k;
    cin >> n >> k;
    if (k == 1) {
        cout << 0 << endl;
        exit(0);
    }
    vector<pair<int, int>> a;  // value, index
    groupSize.assign(n, 0);
    a.reserve(n);
    group.reserve(n);
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        a.emplace_back(t, i);
        group.push_back(i);
    }
    sort(a.rbegin(), a.rend());
    ll sum = 0;
    for (const auto& p : a) {
        int v = p.first, i = p.second;
        int gr = i == 0 ? 0 : getGroupSize(i - 1);
        int gl = ((i == n - 1) ? 0 : getGroupSize(i + 1));
        if (gr == 0 && gl == 0) {
            groupSize[i] = 1;
        } else if (gl == 0 && k - 1 > gr) {
            Union(i - 1, i);
        } else if (gr == 0 && k - 1 > gl) {
            Union(i + 1, i);
        } else if (gl + gr < k - 1) {
            Union(i - 1, i);
            Union(i - 1, i + 1);
        } else {
            continue;
        }
        sum += (ll)v;
    }
    cout << sum << endl;
}
