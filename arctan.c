#include<math.h>
#include<stdio.h>
#define PI 3.14159265
int main(void){
	float ax, ay, az, bx, by, bz, azu, ele, ka, ke;
	printf("? ");
	scanf("%f %f %f %f %f %f", &ax, &ay, &az, &bx, &by, &bz);
	ka = atan2(bx - ax, by - ay);
	printf("Azimuth K = %f\n", ka);
	if(ka < 0){
		printf("Adding 2PI to K...\n");
		ka = ka + (2 * PI);
	}
	azu = ka * (180 / PI);
	printf("Azimuth = %f\n\n", azu);
	ke = sqrt(((bx - ax) * (bx - ax)) + ((by - ay)*(by - ay)));
	printf("Elevation K = %f\n", ke);
	ele = atan((bz - az)/ke) * 180 / PI;
	printf("Elevation = %f\n", ele);
	return 0;
}
