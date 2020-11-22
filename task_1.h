//
// Created by Alester Carletta on 11/21/20.
//
#pragma once


#ifndef TASK_1_H
#define TASK_1_H

#include <iostream>
#include <math.h>
#include <vector>
# include <libc.h>


#define INSIDE 1
#define END 2
#define OUTSIDE 3
#define DEFAULT 0
#define ANSWER 7

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

using Polygon = std::vector<std::vector<int> >;


typedef struct s_data
{
    t_max       limits;
    t_lines     *line;
    t_points    *point;
//    t_points    **polygon; // TODO change to vector -> vector<vector<int>> polygon
    Polygon polygon;
    int         lines_number;
    int         points_number;
    int         size_x;
    int         size_y;
}              t_data;

/*
 * parse.cpp
 */
void    all_parse(t_data *data);
void    all_parse2(t_data *data);


/*
 * bresenham.cpp
 */
void    bresenham_algo(t_data *data);


/*
 * lines.cpp
 */
void    left(t_data *data, t_bresenhem bres, t_lines line);


void    right(t_data *data, t_bresenhem bres, t_lines  line);
void    up(t_data *data, t_bresenhem bres, t_lines line);
void    down(t_data *data, t_bresenhem bres, t_lines line);
/*
 * polygon_output.cpp
 */
void    set_flag(int x, int y, int flag);
int     get_flag(int x, int y);
int     is_inside(int x, int y);
void    polygon_output();
void    make_polygon(t_data *data);
void    fill_polygon_out();


/*
 * solution.cpp
 */
void    solution(t_data *data);


#endif
