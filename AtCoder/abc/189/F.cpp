#include <bits/stdc++.h>
using namespace std;

struct Expr {
    double A = 0.0, B = 0.0;
    Expr operator+(const Expr& other) const {
        return Expr{A + other.A, B + other.B};
    }
    Expr operator+(int x) const {
        return Expr{A, B + x};
    }
    Expr operator-(const Expr& other) const {
        return Expr{A - other.A, B - other.B};
    }
    Expr operator/(int x) const {
        return Expr{A / x, B / x};
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> teleports(k);
    for (int &it : teleports)
        cin >> it;
    if (m <= k) {
        for (int i = 0; i + m - 1 < k; i++) {
            if (teleports[i] + m - 1 == teleports[i + m - 1]) {
                cout << "-1\n";
                return 0;
            }
        }
    }
    unordered_set<int> tp_set(teleports.begin(), teleports.end());
    Expr sum;
    deque<Expr> window{sum};
    for (int i = n - 1; i >= 0; i--) {
        Expr here = tp_set.count(i) ? Expr{1.0, 0.0} : sum / m + 1;
        sum = sum + here;
        window.push_back(here);
        if (n - i >= m) {
            sum = sum - window.front();
            window.pop_front();
        }
    }
    cout << fixed << setprecision(10);
    cout << window.back().B / (1 - window.back().A) << '\n';

    return 0;
}
