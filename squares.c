#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, w;
	// n = pleura , w = paxos
	scanf("%d %d",&n,&w);
	if (n>=2 && n<=13 && w>=1 && n>=2*w)
	{

		for (int line = 0; line < w; line++){
			for (int i = 0; i < n; i++){
				printf("*");
			}
			printf("\n");
		}

		for (int line = 0; line < n-w*2; line++){
			for (int star = 0; star < w; star++){
				printf("*");}
			for(int space=0; space < n-w*2; space++){
				printf(" ");}
			for (int star = 0; star < w; star++){
				printf("*");}
			printf("\n");
		}

		for (int line = 0; line < w; line++){
			for (int i = 0; i < n; i++){
				printf("*");
			}
			printf("\n");
		}
		exit(0);
	}
	printf("Wrong Input\n");
	exit(0);
}