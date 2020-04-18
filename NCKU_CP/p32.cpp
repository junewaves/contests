#include <iostream>
#include <vector>
using namespace std;
#define endl '\n'

int n, n2;
vector<vector<int>> square;
void next(pair<int, int>& p) {
    int i = (p.first + n - 1) % n;
    int j = (p.second + 1) % n;
    if (square[i][j] != -1) {
        i = (p.first + 1) % n;
        j = p.second;
    }
    p.first = i;
    p.second = j;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    n2 = n * n;
    square.resize(n, vector<int>(n, -1));
    pair<int, int> pos = { 0, n >> 1 };
    square[pos.first][pos.second] = 1;
    for (int i = 2; i <= n2; i++) {
        next(pos);
        square[pos.first][pos.second] = i;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << square[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}