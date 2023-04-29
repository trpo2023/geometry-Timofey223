#include <stdio.h>

struct Point {
        float x;
        float y;
};

struct Circle {
        struct Point dot;
        float Rad;
};

float intersection(float i_x, float i_y, float j_x, float j_y, float Rad_i, float Rad_j);

void print_all_intersection(struct Circle **data_object_circle, int cnt);

int scan_file_lines(FILE *file_1, struct Circle **data_object_circle);


