//
// Created by Alester Carletta on 11/21/20.
//
#pragma once


#ifndef TASK_1_H
#define TASK_1_H

#include <iostream>
#include <math.h>
#include <vector>
#include <libc.h>
#include "polygon.h"

//typedef struct s_lines
//{
//    int         x1;
//    int         y1;
//    int         x2;
//    int         y2;
//}               t_lines;
//
//typedef struct s_points
//{
//    int         x;
//    int         y;
//    int         flag;
//}               t_points;
//
//typedef struct  s_max
//{
//    int         min_x;
//    int         max_x;
//    int         min_y;
//    int         max_y;
//}               t_max;
//
//typedef struct  s_bresenham
//{
//    int         d_x;
//    int         d_y;
//    int         err;
//    int         d_err;
//    int         dir_x;
//    int         dir_y;
//}               t_bresenham;
//
//using Polygon   = std::vector <std::vector<int> >;
//using Lines     = std::vector <t_lines>;
//using Points    = std::vector <t_points>;
//
//typedef struct s_data
//{
//    t_max       limits;
//    Lines       line;
//    Points      point;
//    Polygon     polygon;
//    int         lines_number;
//    int         points_number;
//    int         size_x;
//    int         size_y;
//}              t_data;

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
void    left(t_data *data, t_bresenham bres, t_lines line);
void    right(t_data *data, t_bresenham bres, t_lines  line);
void    up(t_data *data, t_bresenham bres, t_lines line);
void    down(t_data *data, t_bresenham bres, t_lines line);


/*
 * solution.cpp
 */
void    solution(t_data *data, Arena *area);


#endif
