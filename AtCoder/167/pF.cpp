#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
int n;
vector<string> s;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    string tmp;
    ll L = 0, R = 0, pl = 0, pr = 0;
    for (int i = 0; i < n; i++) {
        ll l = 0, r = 0;
        cin >> tmp;
        for (const char& c : tmp) {
            if (c == '(')
                l++;
            else if (c == ')' && l > 0)
                l--;
            else
                r++;
        }
        if (l == 0 && r > 0)
            R += r;
        else if (l > 0 && r == 0)
            L += l;
        else if (l > 0 && r > 0) {
            if (pl == 0 && pr == 0) {
                pl = l, pr = r;
            } else {
                if (min(pl, r) > min(pr, l)) {
                    if (pl >= r)
                        pl = pl - r + l;
                    else
                        pr = pr + r - pl, pl = l;
                } else {
                    if (pr >= l)
                        pr = pr - l + r;
                    else {
                        pl = pl + l - pr, pr = r;
                    }
                }
            }
        }
    }
    if (L >= pr && R >= pl && L - pr == R - pl) {
        cout << "Yes";
    } else {
        cout << "No";
    }
}
