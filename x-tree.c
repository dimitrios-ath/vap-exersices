#include <stdio.h>
#include <stdlib.h>

int main(){
	int num, line, counter=1;
	scanf("%d",&num);
	if (num>0 && num<11){
		line = num;
		while(line>0){
			for (int pad = 0; pad < line-1; ++pad){
				printf(" ");}
			for (int star = 0; star < counter; ++star){
				printf("*");}
			printf("\n");
			line-=1;
			counter+=2;
			}
		exit(0);}
	printf("Wrong Input\n");
	exit(0);
}