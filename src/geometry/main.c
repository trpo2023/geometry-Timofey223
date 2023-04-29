#include <stdio.h>
#include <libgeometry/geometry.h>
int main()
{
	FILE *file_1;

	file_1 = fopen("get.txt", "r");
	
	struct Circle *data_object_circle[100];
	
	int kol_vo_obj = scan_file_lines(file_1,data_object_circle);

	print_all_intersection(data_object_circle, kol_vo_obj);
}

