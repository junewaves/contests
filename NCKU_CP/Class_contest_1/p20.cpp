// interactive problem
#include "lib0020.h"
// problem source: https://judge.csie.ncku.edu.tw/problems/20
long long height_limit(long long M) {
    long long up = M, bottom = 1, middle;
    while (1) {
        middle = (up + bottom) / 2;
        if (is_broken(middle)) {
            up = middle;
        } else {
            bottom = middle + 1;
        }
        if (bottom == up) {
            if (up < M || is_broken(M))
                return up - 1;
            else
                return up;
        }
    }
}