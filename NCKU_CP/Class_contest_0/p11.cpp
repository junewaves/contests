#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
// problem source: https://judge.csie.ncku.edu.tw/problems/11
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string input[3];
    cin >> input[0] >> input[1] >> input[2];
    string combine[] = {
        input[0] + input[1] + input[2], input[0] + input[2] + input[1],
        input[1] + input[0] + input[2], input[1] + input[2] + input[0],
        input[2] + input[1] + input[0], input[2] + input[0] + input[1],
    };
    sort(combine, combine + 6);
    cout << combine[5] << "\n";
    return 0;
}