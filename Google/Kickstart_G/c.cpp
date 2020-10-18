#include <bits/stdc++.h>
using namespace std;
 
#include <bits/extc++.h>
using namespace __gnu_pbds;
 
template<typename K, typename V, typename Comp = less<K>>
using ordered_map = tree<K, V, Comp, rb_tree_tag, 
                         tree_order_statistics_node_update>;
 
template<typename K, typename Comp = less<K>>
using ordered_set = ordered_map<K, null_type, Comp>;
 
void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n * 2);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.begin() + n);
    for (int i = 0; i < n; i++) {
        a[i + n] = a[i] + x;
    }
    int ord = (n - 1) / 2;
    bool even = (n % 2 == 0);
    int64_t sum = 0;
    queue<pair<int, int>> que;
    ordered_set<pair<int, int>> os;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        os.insert({a[i], i});
        que.emplace(a[i], i);
    }
    int med = os.find_by_order(ord)->first;
    int64_t cost = 0;
    for (auto p : os) {
        cost += abs(p.first - med);
    }
    int64_t ans = cost;
    for (int i = n; i < 2 * n; i++) {
        cost -= abs(que.front().first - med);
        os.erase(que.front());
        que.pop();
        os.insert({a[i], i});
        que.emplace(a[i], i);
        int new_med = os.find_by_order(ord)->first;
        if (even)
            cost -= new_med - med;
        cost += abs(a[i] - new_med);
        med = new_med;
        ans = min(ans, cost);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    for (int cn = 1; cn <= tt; cn++) {
        cout << "Case #" << cn << ": ";
        solve();
    }
    return 0;
}