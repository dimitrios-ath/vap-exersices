#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
	scanf("%d", &n);
	if (n>=1 && n<=100)
	{
		long a[n], max=0, burles=0;

		for (int i=0; i<n; i++)
		{
			scanf("%ld", &a[i]);

			if (a[i]<0 || a[i]>10E6)
			{
				printf("Wrong Input\n");
				return 0;
			}

			if (a[i]>max)
				max=a[i];
		}

		for (int j=0; j<n; j++)
		{
			burles+=(max-a[j]);
		}
		printf("%ld\n", burles);

	}
	return 0;
}