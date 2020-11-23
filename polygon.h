//
// Created by Alester Carletta on 11/22/20.
//
#pragma once

#include "task_1.h"

class Arena {
private:
    int shift_x;
    int shift_y;
    int size_x;
    int size_y;
    std::vector<std::vector<int> >  polygon;


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
                    std::cout << RED;
                if (polygon[j][i] == OUTSIDE)
                    std::cout << WHITE;
                if (polygon[j][i] == ANSWER)
                    std::cout << GREEN;
                std::cout << "   " << BLACK;
            }
            std::cout << std::endl;
        }
    }

    void    make_polygon(t_data *data) {
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
            polygon.push_back(std::vector <int>());
            while (++i != size_x) {
                polygon[count].push_back(0);
            }
            i = -1;
        }
    }
};

// TODO область видимости глобального экземляра класса