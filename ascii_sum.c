#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int createInt(char letters[])
{
	int sum=0;
	for (int i=0; i<strlen(letters); i++)
	{
		sum+=(int)letters[i];
	}
	return sum;
}

int main()
{
	char text[50];
	scanf("%s",text);
	printf("%d\n",createInt(text));
	return 0;
}