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

struct s_lines
{
    int         x1;
    int         y1;
    int         x2;
    int         y2;
};

struct s_points
{
    int         x;
    int         y;
};

struct  s_max
{
    int         min_x;
    int         max_x;
    int         min_y;
    int         max_y;
};

struct  s_bresenham
{
    int         d_x;
    int         d_y;
    int         err;
    int         d_err;
    int         dir_x;
    int         dir_y;
};

using Polygon   = std::vector <std::vector<int> >;
using Lines     = std::vector <s_lines>;
using Points    = std::vector <s_points>;

struct s_data
{
    s_max       limits;
    Lines       line;
    Points      point;
    Polygon     polygon;
    int         lines_number;
    int         points_number;
    int         size_x;
    int         size_y;
};

class Arena;

/*
 * parse.cpp
 */
void    all_parse(s_data *data);

/*
 * bresenham.cpp
 */
void    bresenham_algo(s_data *data, Arena &area);

/*
 * lines.cpp
 */
void    left(s_data *data, s_bresenham bres, s_lines line, Arena &area);
void    right(s_data *data, s_bresenham bres, s_lines  line, Arena &area);
void    up(s_data *data, s_bresenham bres, s_lines line, Arena &area);
void    down(s_data *data, s_bresenham bres, s_lines line, Arena &area);

/*
 * solution.cpp
 */
void    solution(s_data *data, Arena &area);

/*
 * init.cpp
 */
void     local_init_down(s_data *data, s_bresenham *bres, s_lines line);
void    local_init_up(s_data *data, s_bresenham *bres, s_lines line);
void     local_init_right(s_data *data, s_bresenham *bres, s_lines  line);
void    local_init_left(s_data *data, s_bresenham *bres, s_lines line);
void    init_params(s_data *data, s_bresenham *bres, s_lines line);