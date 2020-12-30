#include <bits/stdc++.h>
using namespace std;

int N, K;

char query(int idx1, int idx2, int len) {
    string res;
    cout << "? " << len << " " << len << endl;
    for (int i = 0; i < len; i++) {
        cout << idx1 + i << " ";
    }
    cout << endl;
    for (int i = 0; i < len; i++) {
        cout << idx2 + i << " ";
    }
    cout << endl;
    cin >> res;
    return res[0];
}

int search(int lo, int hi) {
    int n = lo - 1;
    while (lo < hi) {
        int mid = (lo + hi) / 2, len = mid - n;
        char res = query(1, n + 1, len);
        if (res == 'E')
            lo = mid + 1;
        else
            hi = mid;
    }
    return lo;
}

void solve() {
    cin >> N >> K;

    for (int i = 0; i < 25; i++) {
        int q = rand() % (N - 1) + 2;
        if (query(1, q, 1) == 'S') {
            cout << "! 1" << endl;
            return;
        }
    }

    int len = 1, ans;
    while (len * 2 <= N) {
        char res = query(1, 1 + len, len);
        if (res == 'E') {
            len *= 2;
        } else if (res == 'F') {
            ans = search(len + 1, len * 2);
            cout << "! " << ans << endl;
            return;
        }
        assert(res != 'S' && res != 'W');
    }
    assert(len < N);
    ans = search(len + 1, N);
    cout << "! " << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    srand(time(NULL));
    int _n;
    cin >> _n;
    while (_n--) {
        solve();
    }
}
