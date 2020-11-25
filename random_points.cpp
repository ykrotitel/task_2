//
// Created by Alester Carletta on 11/23/20.
//

#include "task_2.h"

int x;
int y;
int radius;

static int set_flag() {
    if (rand() % 2)
        return 1;
    return -1;
}

double       set_alpha() {
    double sinus;

    if (x > 0 && y > 0) {
        sinus = (double)y / (double)radius;
        return (asin(sinus)/M_PI * 180);
    }
    else if (x <= 0 && y > 0) {
        sinus = (double)abs(x) / (double)radius;
        return (asin(sinus)/M_PI * 180 + 90);
    }
    else if (x <= 0 && y <= 0) {
        sinus = (double)abs(y) / (double)radius;
        return (asin(sinus)/M_PI * 180 + 180);
    }
    sinus = (double)x / (double)radius;
    return (asin(sinus)/M_PI * 180 + 270);
}

void    make_random_points(s_data *data) {
    int count;

    std::cin >> data->N;
    count = -1;
    int i = 5;
    srand(time(nullptr));
    while (++count != data->N) {
        x = (rand() % 101) * set_flag();
        y = (rand() % 101) * set_flag();
        i++;
        radius = sqrt(abs(x)*abs(x) + abs(y)*abs(y));
        data->points.push_back({
                                .x = x,
                                .y = y,
                                .radius = radius,
                                .alpha = set_alpha()});
    }
}
