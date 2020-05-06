#include "lib0043.h"
int n, i, Min = 1, Max = 2;
int main() {
    MagicBalls(&n);
    if (Collision(Min, Max))
        Max = 1, Min = 2;
    for (i = 3; i < n; i += 2) {
        if (Collision(i, i + 1)) {
            if (Collision(i, Max))
                Max = i;
            if (Collision(Min, i + 1))
                Min = i + 1;
        } else {
            if (Collision(i + 1, Max))
                Max = i + 1;
            if (Collision(Min, i))
                Min = i;
        }
    }
    if (i == n) {  // n is odd, need to compare n alone
        if (Collision(n, Max))
            Max = n;
        else if (Collision(Min, n))
            Min = n;
    }
    Choose(Min, Max);
}
