#include <bits/stdc++.h>
using namespace std;

struct Matrix {
    int64_t d[3][3]{};
    Matrix operator*(const Matrix& other) {
        Matrix res;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                for (int k = 0; k < 3; k++)
                    res.d[i][k] += d[i][j] * other.d[j][k];
        return res;
    }
};

using Point = array<int64_t, 2>;

Point project(const Point &a, const Matrix &b) {
    return {a[0] * b.d[0][0] + a[1] * b.d[1][0] + b.d[2][0],
            a[0] * b.d[0][1] + a[1] * b.d[1][1] + b.d[2][1]};
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    vector<Point> P(n);
    for (int i = 0; i < n; i++)
        cin >> P[i][0] >> P[i][1];

    int m;
    cin >> m;
    vector<Matrix> prefix(m + 1);
    for (int i = 0; i < 3; i++)
        prefix[0].d[i][i] = 1;
    for (int i = 1; i <= m; i++) {
        int op, x, y;
        cin >> op;
        if (op & 1)
            x = -1, y = 1;
        else
            x = 1, y = -1;

        Matrix mat;
        if (op <= 2) {
            mat.d[0][1] = x;
            mat.d[1][0] = y;
            mat.d[2][2] = 1;
        } else {
            int p;
            cin >> p;
            mat.d[0][0] = x;
            mat.d[1][1] = y;
            mat.d[2][2] = 1;
            mat.d[2][op - 3] = 2 * p;
        } 

        prefix[i] = prefix[i - 1] * mat;
    }
    
    int q;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        auto [x, y] = project(P[b - 1], prefix[a]);
        cout << x << ' ' << y << '\n';
    }

    return 0;
}
