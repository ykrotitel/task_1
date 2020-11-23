//
// Created by Alester Carletta on 11/21/20.
//

#include "task_1.h"

using namespace std;

void    find_min_max(t_data *data, int count)
{
    if (!count) {
        data->limits.min_x = data->line[count].x1;
        data->limits.max_x = data->line[count].x1;
        data->limits.min_y = data->line[count].y1;
        data->limits.max_y = data->line[count].y1;
    }
    else {

        if (data->line[count].x1 < data->limits.min_x)
            data->limits.min_x = data->line[count].x1;
        if (data->line[count].x1 > data->limits.max_x)
            data->limits.max_x = data->line[count].x1;

        if (data->line[count].y1 < data->limits.min_y)
            data->limits.min_y = data->line[count].y1;
        if (data->line[count].y1 > data->limits.max_y)
            data->limits.max_y = data->line[count].y1;
    }
}

void    all_parse(t_data *data)
{

    int count;
    int x1;
    int y1;
    int x2;
    int y2;

    count = -1;
    cin >> data->lines_number >> data->points_number;

    while (count++ != (data->lines_number - 1)) {
        cin >> x1 >> y1 >> x2 >> y2;
        data->line.push_back({.x1 = x1, .y1 = y1, .x2 = x2, .y2 = y2});
        find_min_max(data, count);
    }
    count = -1;

    while (count++ != (data->points_number - 1)) {
        cin >> x1 >> y1;
        data->point.push_back({.x = x1, .y = y1});
    }

}
