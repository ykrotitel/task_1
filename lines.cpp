//
// Created by Alester Carletta on 11/21/20.
//

#include "task_1.h"

static void    local_init_left(t_data *data, t_bresenhem *bres, t_lines line) {
    bres->d_err = bres->d_y + 1;
    bres->dir_y = (line.y2 - line.y1) > 0 ? 1 : -1;
}

void    left(t_data *data, t_bresenhem bres, t_lines  line) {
    int x1_tmp;
    int y1_tmp;

    local_init_left(data, &bres, line);

    x1_tmp = line.x1;
    y1_tmp = line.y1;

    while (x1_tmp != line.x2) {
        set_flag(x1_tmp, y1_tmp, INSIDE);
        bres.err += bres.d_err;
        if (bres.err >= (bres.d_x + 1)) {
            y1_tmp += bres.dir_y;
            bres.err -= (bres.d_x + 1);
        }
        x1_tmp--;
    }
    set_flag(line.x2, line.y2, END);

}

static void local_init_right(t_data *data, t_bresenhem *bres, t_lines  line) {
    bres->d_err = bres->d_y + 1;
    bres->dir_y = (line.y2 - line.y1) > 0 ? 1 : -1;
}

void    right(t_data *data, t_bresenhem bres, t_lines  line) {
    int x1_tmp;
    int y1_tmp;

    local_init_right(data, &bres, line);

    x1_tmp = line.x1;
    y1_tmp = line.y1;

    while (x1_tmp != line.x2) {
        set_flag(x1_tmp, y1_tmp, INSIDE);
        bres.err += bres.d_err;
        if (bres.err >= (bres.d_x + 1)) {
            y1_tmp += bres.dir_y;
            bres.err -= (bres.d_x + 1);
        }
        x1_tmp++;
    }
    set_flag(line.x2, line.y2, END);
}

static void local_init_up(t_data *data, t_bresenhem *bres, t_lines line) {
    bres->d_err = bres->d_x + 1;
    bres->dir_x = (line.x2 - line.x1) > 0 ? 1 : -1;
}

void    up(t_data *data, t_bresenhem bres, t_lines line) {
    int x1_tmp;
    int y1_tmp;

    local_init_up(data, &bres, line);

    x1_tmp = line.x1;
    y1_tmp = line.y1;

    while (y1_tmp != line.y2) {
        set_flag(x1_tmp, y1_tmp, INSIDE);

        bres.err += bres.d_err;
        if (bres.err >= (bres.d_y + 1)) {
            x1_tmp += bres.dir_x;
            bres.err -= (bres.d_y + 1);
        }
        y1_tmp--;
    }
    set_flag(line.x2, line.y2, END);
}

static void     local_init_down(t_data *data, t_bresenhem *bres, t_lines line) {
    bres->d_err = bres->d_x + 1;
    bres->dir_x = (line.x2 - line.x1) > 0 ? 1 : -1;
}

void    down(t_data *data, t_bresenhem bres, t_lines line) {
    int x1_tmp;
    int y1_tmp;

    local_init_down(data, &bres, line);

    x1_tmp = line.x1;
    y1_tmp = line.y1;

    while (y1_tmp != line.y2) {
        set_flag(x1_tmp, y1_tmp, INSIDE);
        bres.err += bres.d_err;
        if (bres.err >= (bres.d_y + 1)) {
            x1_tmp += bres.dir_x;
            bres.err -= (bres.d_y + 1);
        }
        y1_tmp++;
    }
    set_flag(line.x2, line.y2, END);
}