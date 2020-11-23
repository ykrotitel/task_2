//
// Created by Alester Carletta on 11/23/20.
//

#include "task_2.h"
#include <cstdlib>
//#include <math.h>
#include <cmath>

using namespace std;
int x;
int y;
int radius;
int alpha;

static int set_flag() {
    int f;
    f = rand() % 2;
    if (!f)
        f = -1;
    return (f);
}

double       set_alpha() {
    float sinus;
    if (x > 0 && y > 0) {
        sinus = y / radius;
        return (asin(sinus)/M_PI * 180);
    }
    else if (x <= 0 && y > 0) {
        sinus = abs(x) / radius;
        return ((asin(sinus)/M_PI * 180) + 90);
    }
    else if (x <= 0 && y <= 0) {
        sinus = abs(y) / radius;
        return ((asin(sinus)/M_PI * 180) + 180);
    }
    else if (x > 0 && y < 0) {
        sinus = abs(y) / radius;
        return ((asin(sinus)/M_PI * 180) + 270);
    }
}

void    make_random_points(t_data *data) {
    int count;

    cin >> data->N;
    count = -1;
    while (++count != data->N) {

        x = (rand() % 101) * set_flag();
        y = (rand() % 101) * set_flag();
        radius = sqrt(abs(x)*abs(x) + abs(y)*abs(y));
        data->points.push_back({.x = x, .y = y, .radius = radius, .alpha = set_alpha()});
    }
}
