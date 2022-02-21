#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int num,min_len=50;
	scanf("%d",&num);
	if (num>=1 && num<=100)
	{
		char keimeno[num][50];
		for (int i=0; i<num; i++)
		{
			scanf("%s",keimeno[i]);
			if (strlen(keimeno[i])<min_len)
			{
				min_len = strlen(keimeno[i]);
			}
		}

		for (int j=num-1; j>=0; j--)
		{
			for (int lim=0; lim<min_len; lim++)
			{
				printf("%c", keimeno[j][lim]);
			}
			if(j!=0)
				printf(" ");
			else
				printf("\n");
		}
		return 0;
	}
}