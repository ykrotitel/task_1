//
// Created by Alester Carletta on 11/21/20.
//
#pragma once

#include <cmath>
#include <vector>
#include <libc.h>
#include <iostream>

#define RED "\033[7;31m"
#define WHITE "\033[7;30m"
#define GREEN "\033[7;32m"
#define BLACK "\033[0;30m"

enum Zone {
    DEFAULT = 0,
    INSIDE = 1,
    END = 2,
    OUTSIDE = 3,
    ANSWER = 7,
};

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
}               t_points;

typedef struct  s_max
{
    int         min_x;
    int         max_x;
    int         min_y;
    int         max_y;
}               t_max;

typedef struct  s_bresenham
{
    int         d_x;
    int         d_y;
    int         err;
    int         d_err;
    int         dir_x;
    int         dir_y;
}               t_bresenham;

using Polygon   = std::vector <std::vector<int> >;
using Lines     = std::vector <t_lines>;
using Points    = std::vector <t_points>;

typedef struct s_data
{
    t_max       limits;
    Lines       line;
    Points      point;
    Polygon     polygon;
    int         lines_number;
    int         points_number;
    int         size_x;
    int         size_y;
}               t_data;

class Arena;

/*
 * parse.cpp
 */
void    all_parse(t_data *data);

/*
 * bresenham.cpp
 */
void    bresenham_algo(t_data *data, Arena &area);

/*
 * lines.cpp
 */
void    left(t_data *data, t_bresenham bres, t_lines line, Arena &area);
void    right(t_data *data, t_bresenham bres, t_lines  line, Arena &area);
void    up(t_data *data, t_bresenham bres, t_lines line, Arena &area);
void    down(t_data *data, t_bresenham bres, t_lines line, Arena &area);

/*
 * solution.cpp
 */
void    solution(t_data *data, Arena &area);

/*
 * init.cpp
 */
void     local_init_down(t_data *data, t_bresenham *bres, t_lines line);
void    local_init_up(t_data *data, t_bresenham *bres, t_lines line);
void     local_init_right(t_data *data, t_bresenham *bres, t_lines  line);
void    local_init_left(t_data *data, t_bresenham *bres, t_lines line);
void    init_params(t_data *data, t_bresenham *bres, t_lines line);