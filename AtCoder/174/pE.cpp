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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int& it : a)
        cin >> it;
    sort(a.begin(), a.end(), greater<int>());
    int low = 1, high = 1e9 + 4;
    while (low < high) {
        int mid = low + (high - low) / 2;
        int cuts = 0;
        for (int x : a) {
            if (x <= mid)
                break;
            cuts += (x - 1) / mid;
        }
        if (cuts <= k) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    cout << low << '\n';
    return 0;
}