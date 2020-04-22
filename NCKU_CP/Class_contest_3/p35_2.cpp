#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    long long cnt[2];
    string str[2];
    cin >> n >> str[0] >> str[1];
    for (int t : { 0, 1 }) {
        vector<long long> pre, suf;
        long long cnt_front = 0, cnt_back = 0;
        for (int i = 0; i < n; i++) {
            if (str[t][i] == 'A')
                cnt_front++;
            else if (str[t][i] == 'K')
                pre.push_back(cnt_front);
            if (str[t][n - i - 1] == 'A')
                cnt_back++;
            else if (str[t][n - i - 1] == 'K')
                suf.push_back(cnt_back);
        }
        long long sum = 0;
        int ks = pre.size(), i = 0, j = ks - 1;
        for (; i < ks; i++, j--) {
            sum += pre[i] * suf[j];
        }
        cnt[t] = sum;
    }
    if (cnt[0] == cnt[1])
        cout << "WINWIN\n";
    else if (cnt[0] > cnt[1])
        cout << "LanA WIN\n";
    else
        cout << "LanE WIN\n";
}
