#include <iostream>
using namespace std;
#define endl '\n'

int cnt[101] = { 0 };
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, tmp;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        cnt[tmp]++;
    }
    for (int i = 100; i >= 1; i--) {
        for (int j = 0; j < cnt[i]; j++) {
            cout << i << " ";
        }
    }
    cout << endl;
    return 0;
}