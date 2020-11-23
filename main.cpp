
#include "polygon.h"

int main() {
    t_data data;
    Arena area;

    all_parse(&data);
    area.make_polygon(&data);
    bresenham_algo(&data, area);
    area.fill_polygon_out();
    solution(&data, area);
//    area.polygon_output(); //If you wanna to see the visual solution, just uncomment the line ;)
}