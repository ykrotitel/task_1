//
// Created by Alester Carletta on 11/21/20.
//

#include "task_1.h"

static void    local_init_left(t_data *data, t_bresenhem *bres, t_lines line) {
    bres->d_err = bres->d_y + 1;
    bres->dir_y = line.y2 - line.y1;
    bres->dir_y = (bres->dir_y > 0 ? 1 : -1);
}

void    left(t_data *data, t_bresenhem bres, t_lines  line) {
    int x1_tmp;
    int y1_tmp;

    local_init_left(data, &bres, line);

    x1_tmp = line.x1;
    y1_tmp = line.y1;

    while (x1_tmp != line.x2) {
        data->polygon[y1_tmp][x1_tmp].flag = INSIDE;
//        data->polygon[x1_tmp][y1_tmp].flag = 1;
        bres.err += bres.d_err;
        if (bres.err >= (bres.d_x + 1)) {
            y1_tmp += bres.dir_y;
            bres.err -= (bres.d_x + 1);
        }
        x1_tmp--;
    }
    data->polygon[line.y2][line.x2].flag = INSIDE;
}

static void local_init_right(t_data *data, t_bresenhem *bres, t_lines  line) {
    bres->d_err = bres->d_y + 1;
    bres->dir_y = line.y2 - line.y1;
    bres->dir_y = (bres->dir_y > 0 ? 1 : -1);
}

void    right(t_data *data, t_bresenhem bres, t_lines  line) {
    int x1_tmp;
    int y1_tmp;

    local_init_right(data, &bres, line);

    x1_tmp = line.x1;
    y1_tmp = line.y1;

    while (x1_tmp != line.x2) {
        data->polygon[y1_tmp][x1_tmp].flag = INSIDE;
        bres.err += bres.d_err;
        if (bres.err >= (bres.d_x + 1)) {
            y1_tmp += bres.dir_y;
            bres.err -= (bres.d_x + 1);
        }
        x1_tmp++;
    }
    data->polygon[line.y2][line.x2].flag = INSIDE;
}