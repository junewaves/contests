#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifdef _LOCAL_DEBUG
#include "templates/debug.h"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n = 0;
    cin >> n;
    vector<int> a(n);
    for (int& it : a)
        cin >> it;
    sort(a.begin(), a.end());
    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            for (int k = j + 1; k < n; k++) 
                if (a[i] != a[j] && a[j] != a[k] && a[i] != a[k] && a[i] + a[j] > a[k]) 
                    ans++;
    cout << ans;
    return 0;
}