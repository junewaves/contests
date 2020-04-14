#include <bits/stdc++.h>
using namespace std;
int main(int argc, char* argv[]) {
    vector<int> v = { 0, 0, 0, 0, 1, 1, 1, 1 };
    int i = 0;
    do {
        cout << ++i << ": ";
        for (int j : v) {
            cout << j << " ";
        }
        cout << endl;
    } while (next_permutation(v.begin(), v.end()));
}
