//
// Created by Alester Carletta on 11/23/20.
//

#pragma once

#include <iostream>
#include <vector>
#include <list>

typedef struct s_coord
{
    int         x;
    int         y;
    int         radius;
    double      alpha;
}               t_coord;

using Vector = std::vector <t_coord>;
using List = std::list <t_coord>;

typedef struct  s_data
{
    int         N;
//    Vector      points;
    List        points;
}               t_data;

void    make_random_points(t_data *data);
void    visualizer(t_data *data);
void    remove_useless_points(t_data *data);