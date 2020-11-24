//
// Created by Alester Carletta on 11/24/20.
//

#include "task_2.h"
using namespace std;

int value;

void    quick_sort(t_data *data, int start, int end) {

    auto current = data->points.begin();
    auto iter = data->points.begin();
    auto end_tmp = data->points.begin();
    auto start_tmp = data->points.begin();
    int i;

    i = start - 1;
    if (end - start < 1)
        return ;
    if (end - start > 1) {
        advance(iter, start);
        advance(current, end - 1);
    }
    else {
        advance(iter, start);
        advance(current, end);
    }

    //for debug
    double first_start_value = iter->alpha;
    double second_start_value = current->alpha;
    // for debug
    int f;

    f = (data->N == end ? 0 : 1);
    advance(start_tmp, start);
    advance(end_tmp, end + f);
    while (++i != end) {
        if (iter->alpha > current->alpha) {
            data->points.insert(end_tmp, {.x = iter->x, .y = iter->y, .radius = iter->radius, .alpha = iter->alpha});
            data->points.erase(iter);
        }
        else if (iter->alpha < current->alpha) {
            data->points.insert(start_tmp, {.x = iter->x, .y = iter->y, .radius = iter->radius, .alpha = iter->alpha});
            data->points.erase(iter);
        }
        advance(iter, 1);
    }
    if (end - start == 1)
        return ;
    quick_sort(data, start, ((end / 2) < start ? start + 1 : end / 2));

    int tmp_start = end / 2 + (start == 0 ? 1 : end - start);
    quick_sort(data, tmp_start, end);
//    quick_sort(data, (end / 2) + 1, end);
}

void    remove_useless_points(t_data *data) {
    int count;

    count = -1;
    auto it = data->points.begin();
    while(it != data->points.end()) {
        value = it->radius;
        if (value < 70 || value > 90) {
            data->points.erase(it);
            data->N--;
        }
        advance(it, 1);
    }
    quick_sort(data, 0, data->N);
}