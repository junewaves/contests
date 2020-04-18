#include <bits/stdc++.h>
using namespace std;
#ifndef _VSCODE_DEBUG
#define endl '\n'
#endif
typedef long long int ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    char s[] = "wudixiaoxingxingheclp";
    int n = 21, k = 7;
    int cnt1 = 0, cnt2 = 0, cnt3 = 0;
    for (int i = 0; i < n; i++) {
        cout << s[i] << " \n"[i == n - 1];
        if (i < k && s[i] != s[n - i - 1])
            cnt1++;
    }
    for (int i = 0; i < n; i++) {
        cout << s[n - i - 1] << " \n"[i == n - 1];
    }
    for (int i = 0; i < n - k; i++) {
        cout << s[i] << " \n"[i == n - k - 1];
        if (i < k && s[i] != s[i + k])
            cnt2++;
    }
    for (int i = 0; i < n - k; i++) {
        cout << s[i + k] << " \n"[i == n - k - 1];
    }
    for (int i = k; i < n - k; i++) {
        cout << s[i] << "--" << s[n - i - 1] << " \n"[i == n - k - 1];
        if (s[i] != s[n - i - 1])
            cnt3++;
    }
    cout << "cnt1 = " << cnt1 << endl;
    cout << "cnt2 = " << cnt2 << endl;
    cout << "cnt3 = " << cnt3 << endl;
}
