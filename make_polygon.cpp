//
// Created by Alester Carletta on 11/21/20.
//

#include "task_1.h"

#define SYMB "0123456789ABCDEFGHI"
#define RED "\033[7;31m"
#define WHITE "\033[7;30m"
#define GREEN "\033[7;32m"
#define BLACK "\033[0;30m"
#define CYAN "\033[36m"

int         shift_x;
int         shift_y;
int         size_x;
int         size_y;
std::vector<std::vector<int> > polygon;

void    set_flag(int x, int y, int flag) {
    y += shift_y;
    x += shift_x;
    polygon[y][x].flag = flag;
}

int     is_inside(int x, int y) {
    if (get_flag(x, y) == 0 || get_flag(x, y) == 1)
        return (1);
    else
        return (0);
}

int     get_flag(int x, int y) {
    if (x < -shift_x || x > size_x - shift_x || y < -shift_y || y > size_y - shift_y)
        return (OUTSIDE);
    y += shift_y;
    x += shift_x;
    return (polygon[y][x].flag);
}

static void    set_outside(int x, int y) {
    if (x < 0 || y < 0 || x >= size_x || y >= size_y)
            return ;
    if (polygon[y][x].flag != DEFAULT)
        return ;
    polygon[y][x].flag = OUTSIDE;
    set_outside(x + 1, y);
    set_outside(x - 1, y);
    set_outside(x, y + 1);
    set_outside(x, y - 1);
}

void    fill_polygon_out() {
    int x;
    int y;

    x = -1;
    y = -1;
    while (++x != size_x) {
        set_outside(x, 0);
        set_outside(x, size_y - 1);
    }
    while (++y != size_y) {
        set_outside(0, y);
        set_outside(size_x - 1, y);
    }
}

void    polygon_output() {
    int i;
    int j;

    j = size_y;
    while (j-- != 0) {
        i = -1;
//        cout << CYAN << SYMB[j] << BLACK << " ";
        while (++i != size_x) {
            if (polygon[j][i].flag == INSIDE || polygon[j][i].flag == END)
                cout << RED;
            if (polygon[j][i].flag == OUTSIDE)
                cout << WHITE;
            if (polygon[j][i].flag == ANSWER)
                cout << GREEN;
            cout << "   " << BLACK;
        }
        cout << endl;
    }
//    cout << CYAN << "  0 1 2 3 4 5 6 7 8 9 A\n" << BLACK;
}

void    make_polygon(t_data *data)
{
    int count;

    count = -1;
    size_x = (data->limits.max_x - data->limits.min_x) + 1;
    size_y = (data->limits.max_y - data->limits.min_y) + 1;
    shift_x = -data->limits.min_x;
    shift_y = -data->limits.min_y;

    data->size_x = size_x;
    data->size_y = size_y;

//    data->polygon = (t_points **)(malloc(sizeof(t_points *) * size_y));
    polygon = data->polygon;
    while (count++ != size_y) {
        data->polygon[count] = (t_points *) (malloc(sizeof(t_points) * size_x));
        bzero(data->polygon[count], size_x * sizeof(t_points));
    }
}