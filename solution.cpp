//
// Created by Alester Carletta on 11/22/20.
//

#include "polygon.h"

int x;
int y;

void    solution(s_data *data, Arena &area) {
    int count;
    int answer;

    count = -1;
    answer = 0;
    while (++count != data->points_number) {
        x = data->point[count].x;
        y = data->point[count].y;
        if (area.is_inside(x, y)) {
            answer++;
            area.set_flag(x, y, ANSWER);
        }
    }
    std::cout << answer << std::endl;
}