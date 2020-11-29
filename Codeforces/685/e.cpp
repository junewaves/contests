#include <bits/stdc++.h>
using namespace std;

enum Action { AND, OR, XOR };

int ask(Action i, int l, int r) {
    static const char* act_string[3] = {"AND", "OR", "XOR"};
    cout << act_string[i] << ' ' << l << ' ' << r << endl;
    int ret;
    cin >> ret;
    assert(ret != -1);
    return ret;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> val(n), ans(n), seen(n, -1);
    int x = -1, y = -1;  // try to find a_x == a_y
    for (int i = 1; i < n; i++) {
        val[i] = ask(XOR, 1, i + 1);
        if (x == -1) {
            if (val[i] == 0)
                x = 1, y = i + 1;
            else if (seen[val[i]] != -1)
                x = seen[val[i]], y = i + 1;
            else
                seen[val[i]] = i + 1;
        }
    }
    if (x != -1) {
        int k = ask(AND, x, y);  // get the value of a_x
        ans[0] = val[x - 1] ^ k;
        for (int i = 1; i < n; i++)
            ans[i] = val[i] ^ ans[0];
    } else {
        // find a_1 ^ a_x == n - 1, which implies a_1 & a_x == 0
        for (int i = 1; i < n; i++) {
            if (val[i] == n - 1) {
                x = i + 1;
                break;
            }
        }
        assert(x != -1);
        y = 2 + int(x == 2);
        int ox = val[x - 1];  // a_1 + a_x == a_1 ^ a_x
        int oy = val[y - 1] + 2 * ask(AND, 1, y);  // a_1 + a_y
        int xy = (val[x - 1] ^ val[y - 1]) + 2 * ask(AND, x, y);  // a_x + a_y
        ans[0] = (ox + oy - xy) / 2;
        for (int i = 1; i < n; i++)
            ans[i] = val[i] ^ ans[0];
    }
    cout << '!';
    for (int it : ans) 
        cout << ' ' << it;
    cout << endl;
    return 0;
}