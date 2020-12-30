#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
    int n;
    cin >> n;
    using hash_t = uint64_t;
    vector<hash_t> random(n);
    for (int i = 0; i < n; i++)
        random[i] = rnd();
    vector<int> cnt(n); // count of a_i (mod 3)
    vector<queue<int>> index(n);
    vector<hash_t> hashes(n + 1); // signature of a's prefix at i
    unordered_map<hash_t, int> freq_map; // count of prefixes with the same signature
    freq_map[hashes[0]]++;
    int64_t answer = 0;
    int start = 0;
    for (int i = 0; i < n; i++) {
        int a; cin >> a; --a;
        if (index[a].size() >= 3) {
            int remove = index[a].front();
            index[a].pop();
            // remove sub array  with cnt[a] > 3;
            while (start <= remove) {
                freq_map[hashes[start]]--;
                start++;
            }
        }
        int previous = cnt[a];
        cnt[a] = (cnt[a] + 1) % 3;
        hashes[i + 1] = hashes[i] + (cnt[a] - previous) * random[a];
        answer += freq_map[hashes[i + 1]]++;
        index[a].push(i);
    }
    cout << answer << '\n';
    return 0;
}