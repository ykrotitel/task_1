//
// Created by Alester Carletta on 11/21/20.
//

#include "task_1.h"
#include "polygon.h"

using namespace std;

//void    find_min_max(t_data *data, int count)
//{
//    if (!count) {
//        data->limits.min_x = data->line[count].x1;
//        data->limits.max_x = data->line[count].x1;
//        data->limits.min_y = data->line[count].y1;
//        data->limits.max_y = data->line[count].y1;
//    }
//    else {
//
//        if (data->line[count].x1 < data->limits.min_x)
//            data->limits.min_x = data->line[count].x1;
//        if (data->line[count].x1 > data->limits.max_x)
//            data->limits.max_x = data->line[count].x1;
//
//        if (data->line[count].y1 < data->limits.min_y)
//            data->limits.min_y = data->line[count].y1;
//        if (data->line[count].y1 > data->limits.max_y)
//            data->limits.max_y = data->line[count].y1;
//    }
//}

void    all_parse2(t_data *data)
{
    data->lines_number = 9;
    data->points_number = 2;


    data->line.push_back({-3, 11, 4, 10}); //1
    data->line.push_back({4, 10, 9, 6}); //2
    data->line.push_back({9, 6, 5, 5}); //3
    data->line.push_back({5, 5, 11, 3}); //4
    data->line.push_back({11, 3, 11, -3}); //5
    data->line.push_back({11, -3, 4, 1}); //6
    data->line.push_back({4, 1, 2, -6}); //7
    data->line.push_back({2, -6, -2, 1}); //8
    data->line.push_back({-2, 1, -3, 11}); //9


    data->limits.min_x = -3;
    data->limits.min_y = -6;
    data->limits.max_x = 11;
    data->limits.max_y = 11;

    data->point.push_back({.x = 5, .y = 5});
    data->point.push_back({.x = 100, .y = 0});
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
//        cin >> data->line[count].x1 >> data->line[count].y1;
//        cin >> data->line[count].x2 >> data->line[count].y2;
//        find_min_max(data, count);
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
