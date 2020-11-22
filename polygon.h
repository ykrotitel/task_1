//
// Created by Alester Carletta on 11/22/20.
//

#ifndef UNTITLED_POLYGON_H
#define UNTITLED_POLYGON_H

#include "task_1.h"

#define RED "\033[7;31m"
#define WHITE "\033[7;30m"
#define GREEN "\033[7;32m"
#define BLACK "\033[0;30m"

enum Zone {
    DEFAULT = 0,
    INSIDE = 1,
    END = 2,
    OUTSIDE = 3,
    ANSWER = 7,
};

typedef struct s_lines
{
    int         x1;
    int         y1;
    int         x2;
    int         y2;
}               t_lines;

typedef struct s_points
{
    int         x;
    int         y;
    int         flag;
}               t_points;

typedef struct  s_max
{
    int         min_x;
    int         max_x;
    int         min_y;
    int         max_y;
}               t_max;

typedef struct  s_bresenham
{
    int         d_x;
    int         d_y;
    int         err;
    int         d_err;
    int         dir_x;
    int         dir_y;
}               t_bresenham;

using Polygon   = std::vector <std::vector<int> >;
using Lines     = std::vector <t_lines>;
using Points    = std::vector <t_points>;

typedef struct s_data
{
    t_max       limits;
    Lines       line;
    Points      point;
    Polygon     polygon;
    int         lines_number;
    int         points_number;
    int         size_x;
    int         size_y;
}              t_data;

using namespace std;

class Arena {

private:
    int         shift_x;
    int         shift_y;
    int         size_x;
    int         size_y;
    vector<vector<int> > polygon;

public:
    void    set_flag(int x, int y, int flag) {
        y += shift_y;
        x += shift_x;
        polygon[y][x] = flag;
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
        return (polygon[y][x]);
    }

    void    set_outside(int x, int y) {
        if (x < 0 || y < 0 || x >= size_x || y >= size_y)
            return ;
        if (polygon[y][x] != DEFAULT)
            return ;
        polygon[y][x] = OUTSIDE;
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
            while (++i != size_x) {
                if (polygon[j][i] == INSIDE || polygon[j][i] == END)
                    cout << RED;
                if (polygon[j][i] == OUTSIDE)
                    cout << WHITE;
                if (polygon[j][i] == ANSWER)
                    cout << GREEN;
                cout << "   " << BLACK;
            }
            cout << endl;
        }
    }

public:
    void    make_polygon(t_data *data)
    {
        int count;
        int i;

        count = -1;
        i = -1;

        size_x = (data->limits.max_x - data->limits.min_x) + 1;
        size_y = (data->limits.max_y - data->limits.min_y) + 1;
        shift_x = -data->limits.min_x;
        shift_y = -data->limits.min_y;

        data->size_x = size_x;
        data->size_y = size_y;
        polygon = data->polygon;
        while (count++ != size_y) {
            polygon.push_back(vector <int>());
            while (++i != size_x) {
                polygon[count].push_back(0);
            }
            i = -1;
        }
    }
};

Arena area;

// TODO область видимости глобального экземляра класса
#endif
