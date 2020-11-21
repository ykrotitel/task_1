//
// Created by Alester Carletta on 11/21/20.
//

#ifndef TASK_1_H
#define TASK_1_H

#include <iostream>
#include <math.h>
# include "libc.h"

#define INSIDE 1

using namespace std;

typedef struct s_lines
{
    int         x1;
    int         y1;
    int         x2;
    int         y2;
}               t_lines;

typedef struct s_points
{
    int         x;
    int         y;
    int         flag;
}               t_points;

typedef struct  s_max
{
    int         min_x;
    int         max_x;
    int         min_y;
    int         max_y;
}               t_max;

typedef struct  s_bresenhem
{
    int         d_x;
    int         d_y;
    int         err;
    int         d_err;
    int         dir_x;
    int         dir_y;
}               t_bresenhem;

typedef struct s_data
{
    t_max       limits;
    t_lines     *line;
    t_points    *point;
    t_points    **polygon;
    int         lines_number;
    int         points_number;
    int         size_x;
    int         size_y;
}              t_data;

void    all_parse(t_data *data);
void    make_polygon(t_data *data);
void    bresenham_algo(t_data *data);
void    left(t_data *data, t_bresenhem bres, t_lines line);
void    polygon_output(t_points **polygon, int size_x, int size_y);
void    right(t_data *data, t_bresenhem bres, t_lines  line);
void    all_parse2(t_data *data);





#endif