#include <stdio.h>
#include <stdlib.h>

int main(){
	int n , pentades, upoloipo;
	char k;
	scanf("%d %c",&n,&k);
	if (k>=0x61 && k<=0x7a && n>0){
		pentades = n/5;
		upoloipo = n%5;
		for (int i = 0; i < pentades; ++i){
			printf("%c%c%c%c%c",k,k,k,k,k);
			if (i < pentades-1){
				printf(" ");
			}
		}
		if (upoloipo!=0){
			printf(" ");
			for (int l = 0; l < upoloipo; ++l){
				printf("%c",k);
			}
		}
		printf(".\n");
		exit(0);
	}
	printf("Wrong Input\n");
	exit(0);
}