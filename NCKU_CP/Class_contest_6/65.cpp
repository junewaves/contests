#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> jobs(n), clas(m);
    // map<set<int>, int> mp_job;
    vector<vector<int>> req(n);
    for (int& it : jobs)
        cin >> it;
    for (int& it : clas)
        cin >> it;
    for (int i = 0, t; i < n; i++) {
        cin >> t;
        req[i].resize(t);
        for (int& it : req[i])
            cin >> it, --it;
        // set<int> s;
        // for (int j = 0, v; j < t; j++) {
        //     cin >> v;
        //     s.insert(v);
        // }
        // mp_job[s] += jobs[n];
    }
    int ans = 0, sum = 0;
    // while (true) {
    for (int i = 0; i < n; i++) {
        int max_prof = INT_MIN, best_job = 0;
        for (int i = 0; i < n; i++) {
            if (jobs[i] == -1)
                continue;
            int prof = jobs[i];
            for (int c : req[i]) 
                prof -= clas[c];
            // cout << prof << " ";
            if (prof > max_prof) {
                max_prof = prof;
                best_job = i;
            }
        }
        // if (max_prof < 0)
        //     break;
        // cout << endl;
        sum += max_prof;
        cout << sum << '\n';
        ans = max(sum, ans);
        jobs[best_job] = -1;
        for (int c : req[best_job])
            clas[c] = 0;
    }
    cout << ans << endl;
    return 0;
}
