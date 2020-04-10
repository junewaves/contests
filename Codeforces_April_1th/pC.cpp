#include <bits/stdc++.h>
using namespace std;
#ifndef _VSCODE_DEBUG
#define endl '\n'
#endif
typedef long long int ll;

int main() {
    const int n = 11;
    int nums[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", nums + n - i - 1);
    }
    for (int i = 0; i < n; i++) {
        double a = sqrt(abs(nums[i])) + pow(nums[i], 3) * 5;
        if (a < 400.0) {
            printf("f(%d) = %.2f\n", nums[i], a);
        } else {
            printf("f(%d) = MAGNA NIMIS!\n", nums[i]);
        }
    }

    return 0;
}