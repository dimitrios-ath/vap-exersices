#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	float height,bmi,min,max;
	int weight;
	char category[20];
	scanf("%f %d",&height,&weight);
	if (height >= 0.4 && height <= 2.5 && weight >= 0 && weight <= 200){
		bmi = weight/(height*height);
		if (bmi<20){strcpy(category,"Lipovares");}
		else if (bmi>=20 && bmi<25){strcpy(category,"Normal");}
		else if (bmi>=25 && bmi<30){strcpy(category,"Ypervaro");}
		else if (bmi>=30 && bmi<40){strcpy(category,"Paxisarko");}
		else {strcpy(category,"Sovara Paxisarko");}
		min = 20*height*height;
		max = 24.99*height*height;
		printf("%s\nBMI: %.2f\nMin: %.2f\nMax: %.2f\n", category, bmi, min, max);
		exit(0);
	}
	printf("Wrong input\n");
	exit(0);
}