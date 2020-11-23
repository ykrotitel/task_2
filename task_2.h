//
// Created by Alester Carletta on 11/23/20.
//

#pragma once

#include <iostream>
#include <vector>

typedef struct s_coord
{
    int         x;
    int         y;
    int         radius;
    double      alpha;
}               t_coord;

using Vector = std::vector <t_coord>;

typedef struct  s_data
{
    int         N;
    Vector      points;
}               t_data;

void    make_random_points(t_data *data);
