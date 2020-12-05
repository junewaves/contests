#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> group;
int Find(int v) {
    if (v == group[v])
        return v;
    return group[v] = Find(group[v]);
}
void Union(int u, int v) {
    group[Find(u)] = Find(v);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    group.resize(n);
    iota(group.begin(), group.end(), 0);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        Union(a - 1, b - 1);
    }
    vector<int> cnt(n);
    for (int i = 0; i < n; i++) {
        cnt[Find(i)]++;
    }
    cout << *max_element(cnt.begin(), cnt.end());
    return 0;
}