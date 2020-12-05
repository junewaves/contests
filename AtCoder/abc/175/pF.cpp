#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifdef _LOCAL_DEBUG
#include "templates/debug.h"
#else
#define debug(...)
#endif

bool is_palindrome(const string& s) {
    if (s.size() <= 1u)
        return true;
    int l = 0, r = (int)s.size() - 1;
    while (l < r) {
        if (s[l] != s[r])
            return false;
        l++, r--;
    }
    return true;
}

ll ans = 2e18;
map<pair<string, string>, ll> dis;
priority_queue<pair<ll, pair<string, string>>> que;

void push(const string& s1, const string& s2, ll cost) {
    auto pr = make_pair(s1, s2);
    auto it = dis.find(pr);
    if (it == dis.end() || it->second > cost) {
        dis[pr] = cost;
        que.emplace(-cost, pr);
    }
}

void consider(const string& s1, const string& s2, ll cost) {
    if (cost >= ans)
        return;
    int l1 = s1.size(), l2 = s2.size(), mn = min(l1, l2);
    for (int i = 0; i < mn; i++) {
        if (s1[i] != s2[l2 - i - 1])
            return;
    }
    if (l1 == l2) {
        ans = min(ans, cost);
        return;
    }
    if (l1 > l2) {
        string new_str = s1.substr(mn);
        if (is_palindrome(new_str))
            ans = min(ans, cost);
        else
            push(new_str, "", cost);
    } else {
        string new_str = s2.substr(0, l2 - l1);
        if (is_palindrome(new_str))
            ans = min(ans, cost);
        else
            push("", new_str, cost);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<string> strs(n);
    vector<ll> cost(n);
    for (int i = 0; i < n; i++) {
        cin >> strs[i] >> cost[i];
        consider(strs[i], "", cost[i]);
    }
    while (que.size()) {
        auto [d, pr] = que.top();
        que.pop();
        d *= -1;
        if (d != dis[pr]) {
            continue;
        } else {
            for (int i = 0; i < n; i++) {
                if (pr.first.empty())
                    consider(strs[i], pr.second, d + cost[i]);
                else
                    consider(pr.first, strs[i], d + cost[i]);
            }
        }
    }
    if (ans >= 2e18)
        cout << "-1\n";
    else
        cout << ans << '\n';
    return 0;
}