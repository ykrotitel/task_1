//
// Created by Alester Carletta on 11/21/20.
//

#include "task_1.h"
#define SYMB "0123456789ABCDEFGHI"
#define RED "\033[7;31m"
#define BLACK "\033[0;30m"
#define CYAN "\033[36m"


void    polygon_output(t_points **polygon, int size_x, int size_y)
{
    int i;

    while (size_y-- != 0) {
        i = -1;
//        if (size_y > 9)
//            cout << "\033[36m" << (char)('A' - 10 + size_y) << " \033[30m";
//        else
            cout << CYAN << SYMB[size_y] << BLACK << " ";
        while (++i != size_x) {
            if (polygon[size_y][i].flag)
                cout << RED;
            cout << polygon[size_y][i].flag;
            if (polygon[size_y][i].flag)
                cout << BLACK;
            cout << " ";
        }
        cout << endl;
    }
    cout << CYAN << "  0 1 2 3 4 5 6 7 8 9 A\n" << BLACK;
}