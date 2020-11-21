#include "task_1.h"

int main() {
    t_data data;

    all_parse2(&data);
//    all_parse(&data);
    make_polygon(&data);
    bresenham_algo(&data);
}