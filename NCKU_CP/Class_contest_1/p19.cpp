#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// problem source: https://judge.csie.ncku.edu.tw/problems/19
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k, tmp;
    deque<pair<int, int>> q;
    cin >> n >> k;
    for (int i = 0; i < k - 1; i++) {
        cin >> tmp;
        while (!q.empty() && q.back().first < tmp)
            q.pop_back();
        q.emplace_back(tmp, i);
    }
    for (int i = k - 1; i < n; i++) {
        cin >> tmp;
        while (!q.empty() && q.back().first < tmp)
            q.pop_back();
        q.emplace_back(tmp, i);
        cout << q.front().first << " ";
        if (q.front().second == i - k + 1)
            q.pop_front();
    }
    cout << '\n';
}