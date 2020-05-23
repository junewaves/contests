#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double PI = acos(-1.0);
// const double PI = 3.14159265;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b, h, m;
    cin >> a >> b >> h >> m;
    double x1 = a * cos(h * PI / 6.0 + m * PI / 360.0);
    double y1 = a * sin(h * PI / 6.0 + m * PI / 360.0);
    double x2 = b * cos(m * PI / 30.0);
    double y2 = b * sin(m * PI / 30.0);
    cout << fixed << setprecision(9);
    cout << sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) << '\n';
}
