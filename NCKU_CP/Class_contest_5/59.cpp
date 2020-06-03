#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ll i, n, k, q, r;
        cin >> n >> k;
        r = n % k;
        q = n / k;
        if (n < k) {
            cout << "NO" << endl;
        } else if (n == k) {
            cout << "YES" << endl;
            for (i = 0; i < k; i++) {
                cout << 1 << " ";
            }
            cout << endl;

        } else {
            if (k & 1) {  // k is odd
                if (q > 1) {
                    cout << "YES" << endl;
                    if (r & 1) {  // r is odd
                        cout << (q - 1) + r + k << " ";
                        for (i = 0; i < k - 1; i++) {
                            cout << q - 1 << " ";
                        }
                    } else {  // r is even
                        cout << q + r << " ";
                        for (i = 0; i < k - 1; i++) {
                            cout << q << " ";
                        }
                    }
                    cout << endl;
                } else {  // q = 1
                    if (r & 1) {  // r is odd
                        cout << "NO" << endl;
                    } else {  // r is even
                        cout << "YES" << endl;
                        cout << q + r << " ";
                        for (i = 0; i < k - 1; i++) {
                            cout << q << " ";
                        }
                        cout << endl;
                    }
                }
            } else {  // k is even
                if (r & 1) {  // r is odd
                    cout << "NO" << endl;
                } else {  // r is even
                    cout << "YES" << endl;
                    cout << q + r << " ";
                    for (i = 0; i < k - 1; i++) {
                        cout << q << " ";
                    }
                    cout << endl;
                }
            }
        }
    }
    return 0;
}
