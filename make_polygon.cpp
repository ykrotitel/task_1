//
// Created by Alester Carletta on 11/21/20.
//

#include "task_1.h"

void    make_polygon(t_data *data)
{
    int count;
    int size_squad_x;
    int size_squad_y;

    count = -1;
    size_squad_x = (data->limits.max_x - data->limits.min_x) + 1;
    size_squad_y = (data->limits.max_y - data->limits.min_y) + 1;

    data->size_x = size_squad_x;
    data->size_y = size_squad_y;

    data->polygon = (t_points **)(malloc(sizeof(t_points *) * size_squad_y));
    while (count++ != size_squad_y) {
        data->polygon[count] = (t_points *) (malloc(sizeof(t_points) * size_squad_x));
        bzero(data->polygon[count], size_squad_x * sizeof(t_points));
    }
//    data->polygon[0][1].flag = 1;
//    data->polygon[9][9].flag = 1;
//    polygon_output(data->polygon, data->size_x, data->size_y);

}