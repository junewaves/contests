#include <bits/stdc++.h>
using namespace std;
// problem source: https://judge.csie.ncku.edu.tw/problems/7
int mahou[500001];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, tmp;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> tmp;
        mahou[tmp] = i;
    }
    for (int i = n; i > 0; i--) {
        cout << mahou[i] << " ";
    }
    cout << endl;
}