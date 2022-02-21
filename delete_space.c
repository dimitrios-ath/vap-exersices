#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void deleteSpaces(char original[])
{
	char string[100];
	int len=strlen(original),counter=0;
	
	for (int i=0; i<len; i++)
		string[i]=original[i];

	for (int j=0; j<len; j++)
	{
		if (string[j]!=' ')
		{
			original[counter]=string[j];
			counter++;
		}
	}
	original[counter]='\0';
}

int main()
{
	char text[100];
	fgets(text,100,stdin);
	text[strlen(text)-1]='\0';
	deleteSpaces(text);
	printf("%s\n", text);
	return 0;
}
