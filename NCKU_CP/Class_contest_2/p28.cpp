#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, t;
vector<int> tmp;
vector<pair<int, int>> a;
vector<pair<ll, ll>> res;
void mergeSort(int l, int r) {
    if (r - l <= 1)
        return;
    int m = l + (r - l) / 2;
    // devide
    mergeSort(l, m);
    mergeSort(m, r);
    // merge
    int p = l, q = m, i = l;
    while (i < r) {
        if (q == r || (p != m && a[p].first < a[q].first)) {
            res[a[p].first].second += i - p;
            tmp[i++] = a[p++].first;
        } else {
            res[a[q].first].first += q - i;
            tmp[i++] = a[q++].first;
        }
    }
    for (i = l; i < r; i++)
        a[i].first = tmp[i];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    a.reserve(n);
    res.resize(n, { 0LL, 0LL });
    tmp.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> t;
        a.emplace_back(t, i);
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        a[i].first = i;
    }
    sort(a.begin(), a.end(),
         [](const pair<int, int>& x, const pair<int, int>& y) {
             return x.second < y.second;
         });
    mergeSort(0, n);
    ll sum = 0;
    for (const auto& pp : res) {
        sum += pp.first * pp.second;
    }
    cout << sum << '\n';
}