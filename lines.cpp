//
// Created by Alester Carletta on 11/21/20.
//

#include "polygon.h"

void    left(s_data *data, s_bresenham bres, s_lines  line, Arena &area) {
    int x1_tmp;
    int y1_tmp;

    local_init_left(data, &bres, line);

    x1_tmp = line.x1;
    y1_tmp = line.y1;

    while (x1_tmp != line.x2) {
        area.set_flag(x1_tmp, y1_tmp, INSIDE);
        bres.err += bres.d_err;
        if (bres.err >= (bres.d_x + 1)) {
            y1_tmp += bres.dir_y;
            bres.err -= (bres.d_x + 1);
        }
        x1_tmp--;
    }
    area.set_flag(line.x2, line.y2, END);

}

void    right(s_data *data, s_bresenham bres, s_lines  line, Arena &area) {
    int x1_tmp;
    int y1_tmp;

    local_init_right(data, &bres, line);

    x1_tmp = line.x1;
    y1_tmp = line.y1;

    while (x1_tmp != line.x2) {
        area.set_flag(x1_tmp, y1_tmp, INSIDE);
        bres.err += bres.d_err;
        if (bres.err >= (bres.d_x + 1)) {
            y1_tmp += bres.dir_y;
            bres.err -= (bres.d_x + 1);
        }
        x1_tmp++;
    }
    area.set_flag(line.x2, line.y2, END);
}

void    up(s_data *data, s_bresenham bres, s_lines line, Arena &area) {
    int x1_tmp;
    int y1_tmp;

    local_init_up(data, &bres, line);

    x1_tmp = line.x1;
    y1_tmp = line.y1;

    while (y1_tmp != line.y2) {
        area.set_flag(x1_tmp, y1_tmp, INSIDE);

        bres.err += bres.d_err;
        if (bres.err >= (bres.d_y + 1)) {
            x1_tmp += bres.dir_x;
            bres.err -= (bres.d_y + 1);
        }
        y1_tmp--;
    }
    area.set_flag(line.x2, line.y2, END);
}

void    down(s_data *data, s_bresenham bres, s_lines line, Arena &area) {
    int x1_tmp;
    int y1_tmp;

    local_init_down(data, &bres, line);

    x1_tmp = line.x1;
    y1_tmp = line.y1;

    while (y1_tmp != line.y2) {
        area.set_flag(x1_tmp, y1_tmp, INSIDE);
        bres.err += bres.d_err;
        if (bres.err >= (bres.d_y + 1)) {
            x1_tmp += bres.dir_x;
            bres.err -= (bres.d_y + 1);
        }
        y1_tmp++;
    }
    area.set_flag(line.x2, line.y2, END);
}