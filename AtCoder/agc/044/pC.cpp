#include <bits/stdc++.h>
using namespace std;
void S(vector<int>& a) {
    for (int i = 0; i < (int)a.size(); i++) {
        vector<int> b;
        while (a[i]) {
            b.push_back(a[i] % 3);
            a[i] /= 3;
        }
        for (auto it = b.rbegin(); it != b.rend(); it++) {
            a[i] *= 3;
            if (*it != 0) {
                a[i] += 3 - *it;
            }
        }
    }
}
void R(vector<int>& a, int r) {
    for (int i = 0; i < (int)a.size(); i++) {
        a[i] = (a[i] + r) % (int)a.size();
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    string t;
    cin >> n >> t;
    int s = 0, r = 0;
    vector<int> a((int)pow(3, n));
    for (int i = 0; i < (int)a.size(); i++) {
        a[i] = i;
    }
    for (int i : a)
        cout << i << " ";
    cout << '\n';
    for (char c : t) {
        if (c == 'S') {
            if (r) {
                R(a, r);
                r = 0;
                for (int i : a)
                    cout << i << " ";
                cout << '\n';
            }
            s++;
        } else {
            if (s & 1) {
                S(a);
                s = 0;
                for (int i : a)
                    cout << i << " ";
                cout << '\n';
            }
            r++;
        }
    }
    if (s & 1) {
        S(a);
        s = 0;
        for (int i : a)
            cout << i << " ";
        cout << '\n';
    } else if (r) {
        R(a, r);
        r = 0;
        for (int i : a)
            cout << i << " ";
        cout << '\n';
    }
    // 2 3 4 5 6 7 8 0 1
    // 1 6 8 7 3 5 4 0 2
    // 3 8 1 0 5 7 6 2 4
    // 4 5 6 7 8 0 1 2 3

    // 1 2 01 02
    // 3 6 10 20
    // 4 8 11 22
    // 5 7 12 21
    // 9 18 100 200
    // 10 20 101 202
    // 11 19 102 201
}