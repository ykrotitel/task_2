//
// Created by Alester Carletta on 11/24/20.
//

#include "task_2.h"

std::list<double> alpha;
std::map <double, int> x_map;
std::map <double, int> y_map;
int value;

void    remove_useless_points(s_data *data) {
    auto it = data->points.begin();

    while(it != data->points.end()) {
        value = it->radius;
        if (value < 70 || value > 90) {
            data->points.erase(it);
            data->N--;
        }
        advance(it, 1);
    }
    sort_alpha(data);
}

void    sort_alpha(s_data *data) {

    auto it = data->points.begin();
    while (it != data->points.end()) {
        alpha.push_back(it->alpha);
        x_map.insert({it->alpha, it->x});
        y_map.insert({it->alpha, it->y});
        advance(it, 1);
    }
    alpha.sort();
    show_solution(data);

}

void    show_solution(s_data *data) {
    auto iter = alpha.begin();

    while (iter != alpha.end()) {
        std::cout << "alpha = " << iter.operator*();
        std::cout << ";\t(x, y) = (" << x_map[iter.operator*()];
        std::cout << ", " << y_map[iter.operator*()] << ")" <<std::endl;
        advance(iter, 1);
    }
}