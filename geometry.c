#include <stdio.h>
#include <math.h>
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
struct circle{
	float x;
	float y;
	float Rad;
};

int main()
{
	
	struct circle circle_1[2];
	FILE *type;
	int i = 0;

	type = fopen("get.txt", "r");

	while(fscanf(type, "%f%f%f", &(circle_1[i].x),&(circle_1[i].y),&(circle_1[i].Rad))!=EOF){
		//printf("%f %f %f\n", circle_1[i].x,circle_1[i].y,circle_1[i].Rad);
		i++;
	}
	for(int i = 0; i < 2; i++){
		printf("%d. Circle(%f %f %f)\n\n", i+1, circle_1[i].x, circle_1[i].y,circle_1[i].Rad);
		printf("\tperimeter = %f\n", 2*M_PI*circle_1[i].Rad);
		printf("\tarea = %f\n\n", M_PI*pow(circle_1[i].Rad, 2));
		for(int j = 0; j<2;j++){
			if(i!=j){
				if((intersection(circle_1[i].x,circle_1[i].y,circle_1[j].x,circle_1[j].y,circle_1[i].Rad,circle_1[j].Rad)) == 1){
					printf("\tintersects:\n\n");
					printf("\t\t%d. Circle(%f %f %f)\n",j+1,circle_1[j].x, circle_1[j].y,circle_1[j].Rad);
				}
			}
		}
		printf("\n\n\n");
	}
}

