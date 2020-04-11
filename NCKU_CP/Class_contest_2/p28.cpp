#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, tmp = 0;
ll sum = 0;
vector<int> a, b, first_pos;
vector<pair<ll, ll>> res;
void mergeSort(int l, int r) {
    if (r - l <= 1)
        return;
    int m = (r + l) / 2;
    // devide
    mergeSort(l, m);
    mergeSort(m, r);
    // merge
    int p = l, q = m, i = l;
    copy(a.begin() + l, a.begin() + r, b.begin() + l);
    while (i < r) {
        if (q == r || (p != m && b[p] < b[q])) {
            a[i] = b[p];
            tmp = p - i;
            if (tmp > 0)
                res[first_pos[a[i]]].first += tmp;
            else
                res[first_pos[a[i]]].second -= tmp;
            i++, p++;
        } else {
            a[i] = b[q];
            tmp = q - i;
            if (tmp > 0)
                res[first_pos[a[i]]].first += tmp;
            else
                res[first_pos[a[i]]].second -= tmp;
            i++, q++;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    a.reserve(n);
    first_pos.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        a.push_back(tmp);
        // b.push_back(tmp);
    }
    b = a;
    // Discretization (2 * NlogN)
    tmp = 0;
    sort(b.begin(), b.end());
    for (auto& i : a) {
        i = lower_bound(b.begin(), b.end(), i) - b.begin();
        first_pos[i] = tmp++;
    }
    // use merge sort to count (NlogN)
    // a. values larger than num[i] in the front
    // b. values smller than num[i] in the back
    res.resize(n, { 0, 0 });
    mergeSort(0, n);
    // sum up the result (N)
    for (auto pp : res) {
        sum += pp.first * pp.second;
    }
    cout << sum << '\n';
}