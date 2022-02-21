#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void deleteSpace(char str[])
{
	int counter=0;
	char deleted[200];
	for (int i=0; i<200; i++)
	{
		if (str[i]!=0x20)
		{
			deleted[counter]=str[i];
			counter++;
		}
	}
	deleted[counter]='\0';
	printf("%s\n", deleted);
}

void countLetters(char str[])
{
	int count=0;
	
	for (int i=0; i<200; i++)
	{
		if ((str[i]>='A' && str[i]<='Z') || (str[i]>='a' && str[i]<='z'))
		{
			count++;
		}
	}
	printf("%d\n", count);
	//return counter;
}

int main()
{
	char test[200];
	for (int i=0; i<200; i++)
	{
		test[i]=' ';
	}
	fgets(test, 200, stdin);
	countLetters(test);
	deleteSpace(test);
	return 0;
}