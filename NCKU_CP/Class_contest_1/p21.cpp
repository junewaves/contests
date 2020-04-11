#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// problem source: https://judge.csie.ncku.edu.tw/problems/21
int num[100005], sum = 0;
int n, m, k, pre, now;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    cin >> pre;
    for (int i = 1; i < n; i++) {
        cin >> now;
        num[i] = now - pre;
        sum += num[i];
        pre = now;
    }
    sort(num + 1, num + 1 + n, greater<int>());
    for (int i = 1; i < k; i++) {
        sum -= num[i];
    }
    cout << sum + k << endl;
}