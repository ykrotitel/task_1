
#include "task_1.h"
#include "polygon.h"

using namespace std;

int main() {
    t_data data;

    all_parse2(&data);
    area.make_polygon(&data);
    bresenham_algo(&data);
    area.fill_polygon_out();
    solution(&data, &area);
    area.polygon_output();
}