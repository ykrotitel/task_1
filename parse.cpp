//
// Created by Alester Carletta on 11/21/20.
//

#include "task_1.h"

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

void    all_parse2(t_data *data)
{
    data->lines_number = 4;
    data->points_number = 2;

    data->line = (t_lines *)malloc(sizeof(t_lines) * data->lines_number);
    data->point = (t_points *)malloc(sizeof(t_points) * data->points_number);

    data->line[0].x1 = 0;
    data->line[0].y1 = 10; // 1
    data->line[0].x2 = 10;
    data->line[0].y2 = 7;

    data->line[1].x1 = 10;
    data->line[1].y1 = 7; // 2
    data->line[1].x2 = 10;
    data->line[1].y2 = 0;

    data->line[2].x1 = 10;
    data->line[2].y1 = 0; // 3
    data->line[2].x2 = 0;
    data->line[2].y2 = 4;

    data->line[3].x1 = 0;
    data->line[3].y1 = 4; // 4
    data->line[3].x2 = 0;
    data->line[3].y2 = 10;

    data->limits.max_x = 10;
    data->limits.min_x = 0;
    data->limits.min_y = 0;
    data->limits.max_y = 10;

    data->point[0].x = 5;
    data->point[0].y = 5;

    data->point[1].x = 100;
    data->point[1].y = 0;
}

void    all_parse(t_data *data)
{

    int count;

    count = -1;
    cin >> data->lines_number >> data->points_number;

    data->line = (t_lines *)malloc(sizeof(t_lines) * data->lines_number);
    data->point = (t_points *)malloc(sizeof(t_points) * data->points_number);

    while (count++ != (data->lines_number - 1)) {
        cin >> data->line[count].x1 >> data->line[count].y1;
        cin >> data->line[count].x2 >> data->line[count].y2;
        find_min_max(data, count);
    }
    count = -1;

    while (count++ != (data->points_number - 1)) {
        cin >> data->point[count].x >> data->point[count].y;
    }



//    count = -1;
//    while (count++ != (data->lines_number - 1)) {
//        cout << "(x1; y1) = (" << data->line[count].x1 << "; " << data->line[count].y1 << ")";
//        cout << "\t(x2; y2) = (" << data->line[count].x2 << "; " << data->line[count].y2 << ")\n";
//
//    }
//    count = -1;
//    while (count++ != (data->points_number - 1))
//        cout << "(x; y) = (" << data->point[count].x << "; " << data->point[count].y << ")\n";
}
