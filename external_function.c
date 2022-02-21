#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool ArrayAvg(int *A, int n,float *avg)
{
	if(A!=NULL && n!=0)
	{
		float sum=0;
		for (int i=0; i<n; i++)
			sum+=A[i];
		*avg=sum/n;
		return true;
	}
	return false;
}

float *Davg(int *A, int n)
{
	float *B = malloc(n*sizeof(float));
	float sum=0;
	for (int i=0; i<n; i++)
		sum+=A[i];
	float avg=sum/n;
	for (int i=0; i<n; i++)
		B[i]=A[i]-avg;
	return B;
}