#include <bits/stdc++.h>
using namespace std;
void solve() {
    string sudoku[9];
    for (int i = 0; i < 9; i++) {
        cin >> sudoku[i];
        for (int j = 0; j < 9; j++) {
            if (sudoku[i][j] == '1')
                sudoku[i][j] = '2';
        }
    }
    // int a, b, c, d;
    // for (int i = 0; i < 3; i++) {
    //     for (int j = 0; j < 3; j++) {
    //         a = i * 3 + j;
    //         b = i + j * 3;
    //         c = i * 3 + (j + 1) % 3;
    //         d = (i + 1) % 3 + j * 3;
    //         sudoku[a][b] = sudoku[c][d];
    //     }
    // }
    // sudoku[0][0] = sudoku[1][1];
    // sudoku[1][3] = sudoku[2][4];
    // sudoku[2][6] = sudoku[0][7];
    // sudoku[3][1] = sudoku[4][2];
    // sudoku[4][4] = sudoku[5][5];
    // sudoku[5][7] = sudoku[3][8];
    // sudoku[6][2] = sudoku[7][0];
    // sudoku[7][5] = sudoku[8][3];
    // sudoku[8][8] = sudoku[6][6];
    for (int i = 0; i < 9; i++) {
        cout << sudoku[i] << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _n;
    cin >> _n;
    while (_n--) {
        solve();
    }
    return 0;
}