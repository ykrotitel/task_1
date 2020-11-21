//
// Created by Alester Carletta on 11/21/20.
//

#include "task_1.h"

void    init_params(t_data *data, t_bresenhem *bres, t_lines line)
{
    bres->d_x = abs(line.x2 - line.x1);
    bres->d_y = abs(line.y2 - line.y1);
    bres->err = 0;
    bres->d_err = 0;
}

void    bresenham_algo(t_data *data)
{
    int         count;
    t_lines line;
    t_bresenhem bres;

    count = -1;
    while (count++ != (data->lines_number - 1)) {
        line = data->line[count];

        init_params(data, &bres, line);

        if (line.x1 >= line.x2 && bres.d_x >= bres.d_y) {
            left(data, bres, line);
        }
        else if (line.x2 >= line.x1 && bres.d_x >= bres.d_y) {
            right(data, bres, line);
        }
        else if (line.y1 >= line.y2 && bres.d_y >= bres.d_x) {
            //up (data);
        }
        else if (line.y2 >= line.y1 && bres.d_y >= bres.d_x) {
            //down(data);
        }
        polygon_output(data->polygon, data->size_x, data->size_y);
        cout << endl;
    }
}