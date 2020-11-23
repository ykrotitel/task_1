//
// Created by Alester Carletta on 11/21/20.
//

#include "polygon.h"

void    bresenham_algo(t_data *data, Arena &area)
{
    int         count;
    t_lines     line;
    t_bresenham bres;

    count = -1;
    while (count++ != (data->lines_number - 1)) {
        line = data->line[count];

        init_params(data, &bres, line);

        if (line.x1 >= line.x2 && bres.d_x >= bres.d_y) {
            left(data, bres, line, area);
        }
        else if (line.x2 >= line.x1 && bres.d_x >= bres.d_y) {
            right(data, bres, line, area);
        }
        else if (line.y1 >= line.y2 && bres.d_y >= bres.d_x) {
            up (data, bres, line, area);
        }
        else if (line.y2 >= line.y1 && bres.d_y >= bres.d_x) {
            down(data, bres, line, area);
        }
    }
}