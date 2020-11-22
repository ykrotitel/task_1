//
// Created by Alester Carletta on 11/22/20.
//

#include "task_1.h"

int x;
int y;

void    solution(t_data *data) {
    int count;
    int answer;

    count = -1;
    answer = 0;
    while (++count != data->points_number) {
        x = data->point[count].x;
        y = data->point[count].y;
        if (is_inside(x, y)) {
            answer++;
            set_flag(x, y, ANSWER);
        }
    }
    cout << answer << endl;
}