//
// Created by Alester Carletta on 11/23/20.
//

#include "polygon.h"


void     local_init_down(t_data *data, t_bresenham *bres, t_lines line) {
    bres->d_err = bres->d_x + 1;
    bres->dir_x = (line.x2 - line.x1) > 0 ? 1 : -1;
}

void    local_init_up(t_data *data, t_bresenham *bres, t_lines line) {
    bres->d_err = bres->d_x + 1;
    bres->dir_x = (line.x2 - line.x1) > 0 ? 1 : -1;
}

void     local_init_right(t_data *data, t_bresenham *bres, t_lines  line) {
    bres->d_err = bres->d_y + 1;
    bres->dir_y = (line.y2 - line.y1) > 0 ? 1 : -1;
}

void    local_init_left(t_data *data, t_bresenham *bres, t_lines line) {
    bres->d_err = bres->d_y + 1;
    bres->dir_y = (line.y2 - line.y1) > 0 ? 1 : -1;
}

void    init_params(t_data *data, t_bresenham *bres, t_lines line) {
    bres->d_x = abs(line.x2 - line.x1);
    bres->d_y = abs(line.y2 - line.y1);
    bres->err = 0;
    bres->d_err = 0;
}