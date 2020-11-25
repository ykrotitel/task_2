//
// Created by Alester Carletta on 11/23/20.
//

#pragma once

#include <iostream>
#include <list>
#include <map>
#include <cstdlib>
#include <stdlib.h>
#include <cmath>

struct s_coord
{
    int         x;
    int         y;
    int         radius;
    double      alpha;
};

using List = std::list <s_coord>;

struct  s_data
{
    int         N;
    List        points;
};

void    make_random_points(s_data *data);
void    remove_useless_points(s_data *data);
void    sort_alpha(s_data *data);
void    show_solution(s_data *data);