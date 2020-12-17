#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> t(n), x(n);
        for (int i = 0; i < n; i++)
            cin >> t[i] >> x[i];
        int cmd = 0, ans = 0, pos = 0, speed = 0;
        auto between = [&](int L, int P, int R) -> bool {
            if (L <= R) 
                return L <= P && P <= R;
            else
                return L >= P && P >= R;
        };

        if (x[0] < pos) 
            speed = -1;
        else if (x[0] > pos)
            speed = 1;
        
        for (int i = 1; i < n; i++) {
            int prv = pos;
            // move to the next spot
            pos += speed * (t[i] - t[i-1]);
            // fix overshoot
            if (between(prv, x[cmd], pos))
                pos = x[cmd], speed = 0;
            // check if last command is success
            if (between(prv, x[i-1], pos)) 
                ans++;
            if (speed == 0) {
                // new command;
                cmd = i;
                if (x[i] < pos) 
                    speed = -1;
                else if (x[i] > pos) 
                    speed = 1;
            }
        }
        // check if last command is success
        if (between(pos, x[n-1], x[cmd])) 
            ans++;
        cout << ans << '\n';
    }
    return 0;
}