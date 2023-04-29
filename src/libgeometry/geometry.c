#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

struct Point {
        float x;
        float y;
};

struct Circle {
        struct Point dot;
        float Rad;
};

float intersection(float i_x, float i_y, float j_x, float j_y, float Rad_i, float Rad_j){
        float Razn_x, Razn_y;
        Razn_x = i_x - j_x;
        Razn_y = i_y - j_y;
        if((sqrt(pow(Razn_x, 2)+pow(Razn_y,2)))<=(Rad_i+Rad_j)){
                return 1;
        }
        else{
                return 0;
        }
}

void print_all_intersection(struct Circle **data_object_circle, int cnt){
	
	for(int i = 0; i < cnt; i++){
                printf("%d. Circle(%f, %f, %f)\n\n", i+1, data_object_circle[i]->dot.x, data_object_circle[i]->dot.y,data_object_circle[i]->Rad);
                printf("\tperimeter = %f\n", 2*M_PI*data_object_circle[i]->Rad);
                printf("\tarea = %f\n\n", M_PI*pow(data_object_circle[i]->Rad, 2));

                for(int j = 0; j<cnt;j++){
                        if(i!=j){
                                if((intersection(data_object_circle[i]->dot.x,data_object_circle[i]->dot.y,\
                                                                data_object_circle[j]->dot.x,data_object_circle[j]->dot.y,\
                                                                data_object_circle[i]->Rad,data_object_circle[j]->Rad)) == 1){
                                        printf("\tintersects:\n\n");
                                        printf("\t\t%d. Circle(%f, %f, %f)\n",j+1,data_object_circle[j]->dot.x, data_object_circle[j]->dot.y,data_object_circle[j]->Rad);
                                }
                        }
                }
                printf("\n\n\n");
        }
}

int scan_file_lines(FILE *file_1, struct Circle **data_object_circle){

        char* object;
        char line[100];
        char line_1[100];

        int cnt = 0;
        int kol_vo_str = 0;

        struct Circle *str_now = malloc(sizeof(*str_now));
	//str_now->dot = malloc(sizeof(*str_now->dot));

        while ((fgets(line, 100, file_1)) != 0) {
                printf("\n");
                strcpy(line_1, line);
                object = strtok(line_1, "(");
                kol_vo_str++;
                if (strcmp(object, "circle") == 0) {
                        if ((sscanf(line,"circle(%f %f, %f)",&str_now->dot.x,&str_now->dot.y, &str_now->Rad)) == 3){
                                
				data_object_circle[cnt] = malloc(sizeof(struct Circle));

				data_object_circle[cnt]->dot.x = str_now->dot.x;
                                data_object_circle[cnt]->dot.y = str_now->dot.y;
                                data_object_circle[cnt]->Rad = str_now->Rad;
                                cnt++;
                        }
                        else{
                                //printf("%s(%f %f, %f)\n",line_1,str_now->dot.x,str_now->dot.y,str_now->Rad);
				printf("%s\n", line);
                                printf("\n\tError at column %d: Incorect data of points of circle \n", kol_vo_str);
                        }
                }
                else{
                        printf("%s\n",line);
                        printf("\tError at column %d: Incorect type format \n",kol_vo_str);
                }
        }

        printf("\n\n\n");
	return cnt;
}

