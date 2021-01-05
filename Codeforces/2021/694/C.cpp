#include <bits/stdc++.h>
using namespace std;

int ask(int i) {
    cout << "? " << i + 1 << endl;
    int ret;
    cin >> ret;
    return ret;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    int low = 0, high = n, wing = 0;
    while (high - low > 1) {
        if (2 * wing + 1 >= high - low) {
            int mid = (low + high) / 2;
            int ret = ask(mid);
            if (ret == k) 
                low = mid, high = mid + 1;
            else if (ret > k)
                high = mid;
            else
                low = mid + 1;
        } else {
            int mid = low + wing;
            if (ask(mid) > k)
                high = mid;
            else
                low = mid;
        }
        wing = min(wing + 1, (n - 2) / 2);
    }
    cout << "! " << low + 1 << endl;
    return 0;
}