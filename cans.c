#include <stdio.h>
#include <stdlib.h>

int main()
{
	unsigned int N;
	scanf("%d",&N);
	if (N>=2 && N<=100000)
	{
		long A[N], B[N], xoritikotita=0, sum_ml=0;
		for (int i=0; i<N; i++)
		{
			scanf("%ld", &A[i]);
			if (A[i]<0 || A[i]>1000000000)
			{
				printf("Wrong Input\n");
				return 0;
			}
			sum_ml+=A[i];

		}
		for (int i=0; i<N; i++)
		{
			scanf("%ld", &B[i]);
			if (B[i]<0 || B[i]>1000000000)
			{
				printf("Wrong Input\n");
				return 0;
			}
		}

		for (int a=0; a<N; a++)
		{
			for (int b=0; b<N; b++)
			{	
				if (a!=b)
				{
					xoritikotita=B[a]+B[b];
					if (sum_ml<=xoritikotita)
					{
						printf("Yes\n");
						return 0; 
					}
				}
			}
		}
		printf("No\n");
		return 0; 
	}
	printf("Wrong Input\n");
	return 0;
}