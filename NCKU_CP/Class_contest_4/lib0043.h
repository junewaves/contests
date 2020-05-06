#ifndef LIB0043_H
#define LIB0043_H

#include <stdio.h>
#include <stdlib.h>

int _n, *_balls, _limit;

void MagicBalls(int* N) {
    scanf("%d", &_n);
    _balls = (int*)malloc(sizeof(int) * (_n + 1));
    _limit = _n * 1.5;
    for (int i = 1; i <= _n; i++)
        scanf("%d", &_balls[i]);
    *N = _n;
}

int legal(int x) {
    return 1 <= x && x <= _n;
}

int Collision(int Uth, int Bt) {
    static int _count = 0;
    if (++_count > _limit)
        printf("Wrong Answer: space distorsion\n"), exit(0);
    if (legal(Uth) && legal(Bt) && Uth != Bt)
        return _balls[Uth] >= _balls[Bt];
    printf("Wrong Answer: instrument explosion\n"), exit(0);
}

int _min(int a, int b) {
    return a < b ? a : b;
}

int _max(int a, int b) {
    return a > b ? a : b;
}

void Choose(int MinBall, int MaxBall) {
    int mi = 2000000000, mx = 0;
    if (legal(MinBall) && legal(MaxBall) && MinBall != MaxBall) {
        for (int i = 1; i <= _n; i++)
            mi = _min(mi, _balls[i]), mx = _max(mx, _balls[i]);
        if (mi == _balls[MinBall] && mx == _balls[MaxBall])
            printf("OK, get max power\n"), exit(0);
    }
    printf("Wrong Answer: insufficient resonance\n"), exit(0);
}

#endif
